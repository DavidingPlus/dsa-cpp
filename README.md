# source-code-vs2019

VS2019 版示例代码包。

1. 原链接：[https://cloud.tsinghua.edu.cn/d/92a0694dee2242c88466/](https://cloud.tsinghua.edu.cn/d/92a0694dee2242c88466/)

2. 转换乱码到 utf-8 编码的工具：[https://github.com/clorymmk/CodeTransmit](https://github.com/clorymmk/CodeTransmit)

3. 使用 VS 2019 和命令行 MSBuild 进行编译（Visual Studio 可以一键编译，但是我不喜欢）。

   ```powershell
   MSBuild .\src\dsacpp.sln -t:Rebuild -p:Configuration=Release
   ```

    编译生成的可执行文件在 _executable 目录中对应的 exe。

