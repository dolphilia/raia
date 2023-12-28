//
// Created by dolphilia on 2023/10/07.
//

#include "test.h"
#include <iostream>

using nlohmann_json_t = nlohmann::json;

UTEST(raia_file, raia_file_exist) {
    {
        // ファイルが存在しないパターン
        const char *args = R"(
            {
                "path": "non-exist.txt"
            }
        )";
        const char *ret = raia_file_exist(args);
        nlohmann_json_t json = nlohmann_json_t::parse(ret);
        auto result = json["exist"].get<int>();
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
        nlohmann_json_t json = nlohmann_json_t::parse(ret);
        auto result = json["exist"].get<int>();
        ASSERT_EQ(result, 1);
        free((void *) ret);
    }
}

UTEST_STATE();

int main(int argc, const char *const argv[]) {
    // テストの準備をする

    // 現在の作業ディレクトリに空のテキストファイルを作成する
    std::ofstream file("exist.txt", std::ios::app);

    return utest_main(argc, argv);
}

//UTEST_MAIN();