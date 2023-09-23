# Lythium

Simple C++ Logging Library

## Usage

Exmaple use

```c++
#include <Logger.h>

int main(){
    Lythium::Logger::Init("path/to/log/folder", Lythium::LOGGER::DEBUG);
    Lythium::Logger myLogger("MyProgram");
    myLogger.Warn("This is a warning");
}
```
