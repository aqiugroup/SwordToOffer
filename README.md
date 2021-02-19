## 1. C++

### 依赖

- cmake
- googletest

### 用法

生成模板，将会在src目录下生成相应模板，根据题目进行修改即可。

因为C++不支持数字打头的函数名，那就添加一个后缀，${PROBLEM_NAME}_{ID}.名字作为solution_name吧。

```shell
./generate_template ${PROBLEM_NAME}_{ID}
```

调试运行

```shell
./code ${PROBLEM_NAME}_{ID}
```
