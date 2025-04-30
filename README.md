# arduino-epaper-display-epd1in54-v2
Arduino E-Paper Display epd1in54-v2

## Original from
https://github.com/waveshareteam/e-Paper

## Functions
### epd
```
grep --color -P -o 'epd\.\w+' src/epd1in54_V2.ino.disabled | sort -u
epd.Clear
epd.Display
epd.DisplayFrame
epd.DisplayPartBaseImage
epd.DisplayPartFrame
epd.HDirInit
epd.LDirInit
epd.SetFrameMemory
epd.SetFrameMemoryPartial
epd.Sleep
```

### paint
```
grep --color -P -o 'paint\.\w+' src/epd1in54_V2.ino.disabled | sort -u
paint.Clear
paint.DrawCircle
paint.DrawFilledCircle
paint.DrawFilledRectangle
paint.DrawLine
paint.DrawRectangle
paint.DrawStringAt
paint.GetHeight
paint.GetImage
paint.GetWidth
paint.h
paint.SetHeight
paint.SetWidth
```
