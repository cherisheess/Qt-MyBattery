# MyBattery (Qt Custom Widget)

A Qt Widgets demo featuring a custom-drawn battery indicator (`MyBattery`) with gradient fill, alarm coloring, and a simple host window (`widget`).

- Works with Qt 5 (Widgets) and C++17
- Built via qmake using the included `untitled7-MyBattery.pro`

## Requirements
- Qt 5.12+ (or Qt 6 built with Widgets module)
- qmake and a C++17 compiler
- Linux/macOS/Windows

## Build and Run (CLI)
```bash
cd /workspace
qmake untitled7-MyBattery.pro
make -j"$(nproc)"
./untitled7-MyBattery
```
On Windows (MinGW):
```bash
qmake untitled7-MyBattery.pro
mingw32-make -j4
./release/untitled7-MyBattery.exe
```

## Open in Qt Creator
- Open `untitled7-MyBattery.pro`
- Configure a Desktop kit (Qt Widgets)
- Build and Run

## What’s Included
- `mybattery.h/.cpp/.ui`: Custom battery widget
- `widget.h/.cpp/.ui`: Simple host window
- `main.cpp`: Application entry point
- `untitled7-MyBattery.pro`: qmake project file

## Documentation
- API Reference: see `docs/API.md`
- Usage & Examples: see `docs/USAGE.md`

### Generate HTML Docs
- Install Doxygen (`sudo apt-get install doxygen graphviz` on Debian/Ubuntu)
- Run:
```bash
cd /workspace
doxygen docs/Doxyfile
xdg-open docs/site/html/index.html
```

## Screenshots
- The battery level is controlled by the internal horizontal slider in `MyBattery`.

## Notes
- The current implementation does not expose public setters for the battery level or colors; the level is driven by the internal slider. See `docs/USAGE.md` for extension ideas.
