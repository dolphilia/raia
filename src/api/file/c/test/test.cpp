//
// Created by dolphilia on 2023/10/07.
//

#include "test.h"
#include <iostream>

using json_t = nlohmann::json;

int test_file_exist(const char *path) {
    const char *format = R"(
        {
            "path": "%s"
        }
    )";
    char args[512];
    snprintf(args, sizeof(args), format, path);
    args[sizeof(args) - 1] = '\0';

    const char *ret = raia_file_exist(args);

    json_t json = json_t::parse(ret);
    auto result = json["result"].get<int>();
    return result;
}

UTEST(raia_file, raia_file_exist) {
    {
        // ファイルが存在しないパターン
        const char *args = R"(
            {
                "path": "non-exist.txt"
            }
        )";
        const char *ret = raia_file_exist(args);
        json_t json = json_t::parse(ret);
        auto result = json["result"].get<int>();
        ASSERT_EQ(result, 0);
        free((void *) ret);
    }
    {
        // ファイルが存在するパターン
        const char *args = R"(
            {
                "path": "exist.txt"
            }
        )";
        const char *ret = raia_file_exist(args);
        json_t json = json_t::parse(ret);
        auto result = json["result"].get<int>();
        ASSERT_EQ(result, 1);
        free((void *) ret);
    }
}

//UTEST_MAIN();

UTEST_STATE();

int main(int argc, const char *const argv[]) {
    // テストの準備をする

    // 現在の作業ディレクトリに空のテキストファイルを作成する
    std::ofstream file("exist.txt", std::ios::app);

    return utest_main(argc, argv);
}