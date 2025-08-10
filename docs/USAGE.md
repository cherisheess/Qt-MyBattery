## Usage & Examples

### Quick Start (Code)
Add the battery widget to a Qt Widgets application:

```cpp
#include <QApplication>
#include "mybattery.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  MyBattery battery;
  battery.resize(320, 120);
  battery.show();

  return app.exec();
}
```

### Embedding in a Layout
```cpp
#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include "mybattery.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  QVBoxLayout* layout = new QVBoxLayout(&window);

  MyBattery* battery = new MyBattery(&window);
  layout->addWidget(battery);

  window.resize(400, 200);
  window.show();

  return app.exec();
}
```

### Controlling the Level
- The current implementation drives the battery level from an internal `QSlider` (`horizontalSlider`) defined in `mybattery.ui`.
- There is no public `setValue(int)` or `setAlarmValue(int)` yet.

Workarounds:
- Control the internal slider via Designer at design-time (initial value).
- Extend the class (recommended) to add public setters/getters.

### Suggested Extensions (API Surface)
Add these methods to make the widget reusable in other contexts:

```cpp
// In mybattery.h (public)
void setValue(int value);
int value() const;
void setAlarmValue(int value);
int alarmValue() const;
void setNormalColors(const QColor& start, const QColor& end);
void setAlarmColors(const QColor& start, const QColor& end);
```

And implement them to update internal state and call `update()`.

### Build Instructions (CLI)
See the root `README.md` for platform-specific steps. For Linux/macOS:
```bash
qmake untitled7-MyBattery.pro
make -j"$(nproc)"
./untitled7-MyBattery
```

### Running the Demo
The demo `main.cpp` shows both the `MyBattery` widget and a simple `widget` window. The slider in `MyBattery` will adjust the level and switch to alarm colors when below the threshold (default 30).