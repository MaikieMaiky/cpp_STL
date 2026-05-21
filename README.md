# cpp_STL

C++ 标准库（STL）学习与示例代码，按主题分目录存放，每个 `.cpp` 文件可单独编译运行。

## 如何编译运行

在项目根目录或对应子目录下执行（以 `g++` 为例）：

```bash
g++ string/01_string构造函数.cpp -o app 
./app
```

将源文件路径换成你要运行的示例即可。

## 目录结构

```
cpp_STL/
├── deque/           # std::deque 示例 + README（本目录示例索引）
├── example/         # 综合案例 + README（本目录示例索引）
├── list/            # std::list 示例 + README（本目录示例索引）
├── map/             # std::map 示例 + README（本目录示例索引）
├── queue/           # std::queue 示例 + README（本目录示例索引）
├── set/             # std::set 示例 + README（本目录示例索引）
├── stack/           # std::stack 示例 + README（本目录示例索引）
├── string/          # std::string 示例 + README（本目录示例索引）
├── vector/          # std::vector 示例 + README（本目录示例索引）
├── LICENSE
└── README.md
```

## 示例索引

按容器查看全部示例（表格与源文件链接在各目录内维护）：

- [deque 示例索引](deque/README.md) — `std::deque`
- [example 综合案例](example/README.md) — 综合案例
- [list 示例索引](list/README.md) — `std::list`
- [map 示例索引](map/README.md) — `std::map`
- [queue 示例索引](queue/README.md) — `std::queue`
- [set 示例索引](set/README.md) — `std::set`
- [stack 示例索引](stack/README.md) — `std::stack`
- [string 示例索引](string/README.md) — `std::string`
- [vector 示例索引](vector/README.md) — `std::vector`

新增容器时：新建目录、在该目录添加 `README.md` 作为示例表，并在本节增加一条链接。


## 说明

- 本仓库以**教学与查阅**为主，示例力求直观，可按需修改参数观察输出。

## 许可证

本项目采用 [MIT License](LICENSE) 授权。

