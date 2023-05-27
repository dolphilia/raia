//
// Created by dolphilia on 2022/12/10.
//

#include "util_file.h"

void get_directories_recursive(const char *path, char ***directories, size_t *count) {
    char **current_directories = NULL;
    size_t current_count = 0;
    get_directories(path, &current_directories, &current_count);

    for (size_t i = 0; i < current_count; i++) {
        *directories = realloc(*directories, (*count + 1) * sizeof(char *));
        (*directories)[*count] = current_directories[i];
        (*count)++;

        size_t subdir_len = strlen(path) + 1 + strlen(current_directories[i]) + 1;
        char *subdir = malloc(subdir_len);
        snprintf(subdir, subdir_len, "%s/%s", path, current_directories[i]);

        get_directories_recursive(subdir, directories, count);

        free(subdir);
    }

    free(current_directories);
}

#ifdef __WINDOWS__
void get_directories(const char *path, char ***directories, size_t *count) {
    WIN32_FIND_DATA find_data;
    char search_path[MAX_PATH];
    snprintf(search_path, sizeof(search_path), "%s\\*", path);

    HANDLE h_find = FindFirstFile(search_path, &find_data);
    if (h_find == INVALID_HANDLE_VALUE) {
        //fprintf(stderr, "Error opening directory\n");
        return;
    }

    do {
        if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (strcmp(find_data.cFileName, ".") != 0 && strcmp(find_data.cFileName, "..") != 0) {
                (*count)++;
                *directories = realloc(*directories, *count * sizeof(char *));
#ifndef __WINDOWS__
                (*directories)[*count - 1] = strdup(find_data.cFileName);
#endif
#ifdef __WINDOWS__
                (*directories)[*count - 1] = _strdup(find_data.cFileName);
#endif
            }
        }
    } while (FindNextFile(h_find, &find_data));

    FindClose(h_find);
}
#else

void get_directories(const char *path, char ***directories, size_t *count) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    struct stat st;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &st) == 0 && S_ISDIR(st.st_mode)) {
            (*count)++;
            *directories = realloc(*directories, *count * sizeof(char *));
            (*directories)[*count - 1] = strdup(entry->d_name);
        }
    }

    closedir(dir);
}

#endif

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd // Windowsでは_getcwdを使用します
#else
#include <unistd.h>
#endif

char* get_current_path() {
    char* cwd = (char*) malloc(1024);
    if (cwd == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (getcwd(cwd, 1024) == NULL) {
        perror("getcwd");
        free(cwd);
        exit(EXIT_FAILURE);
    }

    return cwd;
}

char *get_exe_path() {
#ifdef __LINUX__
    char path[1024];
    ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len == -1) {
        perror("Error resolving executable path");
        return "";
    }
    path[len] = '\0';
    char* dir = dirname(path);
    return dir;
#endif
#ifdef __MACOS__
    char path[1024];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) != 0) {
        fprintf(stderr, "Error resolving executable path: buffer too small\n");
        return "";
    }
    char *dir = dirname(path);
    return dir;
#endif
#ifdef __WINDOWS__
    TCHAR exe_path[MAX_PATH];
    TCHAR exe_dir[MAX_PATH];
    DWORD length = GetModuleFileName(NULL, exe_path, MAX_PATH);

    if (length > 0 && length < MAX_PATH) {
        TCHAR* last_slash = _tcsrchr(exe_path, '\\');
        if (last_slash != NULL) {
            WCSNCPY(exe_dir, exe_path, last_slash - exe_path);
            exe_dir[last_slash - exe_path] = '\0';

            _tprintf(TEXT("executable file directory: %s\n"), exe_dir);
        }
        else {
            _tprintf(TEXT("Error: path of executable file is incorrect.\n"));
        }
    }
    else {
        _tprintf(TEXT("Error: could not obtain path to executable file.\n"));
    }
    return (char *)exe_dir;
#endif
}

int file_check_path(const char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) == -1) {
        return 0; // path does not exist
    }
    if (S_ISREG(path_stat.st_mode)) {
        return 1; // path points to a file.
    }
    if (S_ISDIR(path_stat.st_mode)) {
        return 2; // path points to a directory.
    }
    return 0; // path does not exist
}

char *file_load_string(const char *filename) {
    size_t file_index = 0;
    char *str = NULL;
    FILE *file_ptr;

#ifdef __WINDOWS__
    fopen_s(&file_ptr, filename, "r");
#else
    file_ptr = fopen(filename, "r");
#endif

    if (file_ptr == NULL) {
        printf("Failed to load file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fseek(file_ptr, 0, SEEK_END);
    const size_t initial_size = ftell(file_ptr);
    size_t buffer_size = initial_size + 4;
    str = (char *) malloc(buffer_size + 1);
    fseek(file_ptr, 0, SEEK_SET);
    for (;;) {
        const int c = fgetc(file_ptr);
        if (c == EOF) {
            break;
        }
        const char ch = (char) c;
        if (buffer_size <= file_index) {
            buffer_size *= 2;
            str = (char *) realloc(str, buffer_size);
        }
        str[file_index] = ch;
        file_index++;
    }
    str[file_index] = '\0';
    fclose(file_ptr);
    return str;
}

int file_save_string(const char *filename, const char *content) {
    FILE *file;
#ifdef __WINDOWS__
    fopen_s(&file, filename, "w");
#else
    file = fopen(filename, "w");
#endif
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    if (fputs(content, file) == EOF) {
        perror("Error writing to file");
        fclose(file);
        return 2;
    }
    if (fclose(file) != 0) {
        perror("Error closing file");
        return 3;
    }
    return 0;
}

uint8_t *file_load_binary(const char *filename, size_t *file_size) {
    FILE* file;
#ifdef __WINDOWS__
    fopen_s(&file, filename, "rb");
#else
    file = fopen(filename, "rb");
#endif
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    uint8_t *buffer = (uint8_t *)malloc(size);
    if (buffer == NULL) {
        printf("Error allocating memory for file buffer.\n");
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, size, file);
    if (bytes_read != size) {
        printf("Error reading file: %s\n", filename);
        fclose(file);
        free(buffer);
        return NULL;
    }

    fclose(file);

    if (file_size) {
        *file_size = size;
    }

    return buffer;
}

int file_save_binary(const char *filename, uint8_t *data, size_t data_size) {
    FILE* file;
#ifdef __WINDOWS__
    fopen_s(&file, filename, "wb");
#else
    file = fopen(filename, "wb");
#endif
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    size_t written = fwrite(data, sizeof(uint8_t), data_size, file);
    fclose(file);

    if (written != data_size) {
        printf("Error: Unable to write all data to file %s\n", filename);
        return 1;
    }

    return 0;
}