#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <queue>
#include <sys/stat.h>

/**
 * @param argc 引数の数
 * @param argv 引数の文字列
 */
int main(int argc, const char *argv[])
{
    // NOTE: argv[0] は自身のコマンド名が入っている
    const int arg_start_index = 1;

    /*
     * バリデーション処理（引数）
     */
    if (argc <= arg_start_index)
    {
        std::cout << "Invalid argument." << std::endl;
        return -1;
    }

    std::queue<std::string> paths;

    /*
     * バリデーション処理（パス）
     */
    for (int i = arg_start_index; i < argc; i++)
    {
        // ハイフンが1~2個戦闘についていたらオプション指定の処理（予定）

        struct stat st;
        std::string path = argv[i];

        bool notFound = stat(argv[i], &st) != 0;
        if (notFound)
        {
            std::cout << "The file does not exist. " << path << std::endl;
            continue;
        }
        bool isDirectory = (st.st_mode & S_IFMT) == S_IFDIR;
        if (isDirectory)
        {
            std::cout << "Directory path cannot be specified. " << path << std::endl;
        }

        std::ifstream file(path);

        if (file.fail())
        {
            std::cout << "Failed to open file. " << path << std::endl;
            continue;
        }

        paths.push(path);
    }

    // 1行の文字列を保持する変数。文字数は可変するのでstd::stringで取得
    std::string line_str;

    while (!paths.empty())
    {
        std::string path = paths.front();
        std::ifstream file(path);

        // find conflict markers
        while (!file.eof())
        {
            getline(file, line_str);

            std::cout << line_str << std::endl;
        }
        paths.pop();
    }



    return EXIT_SUCCESS;
}
