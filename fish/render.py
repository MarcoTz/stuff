import os
from dataclasses import dataclass
from PIL import Image, ImageDraw


@dataclass
class Line:
    start: (int, int)
    end: (int, int)


fish_file = open("fish.txt")
lines = []
x_min = 100000
x_max = 0
y_min = 100000
y_max = 0

for line in fish_file:
    line = line.replace("(", "").replace(")", "").strip()
    coords = line.split(",")
    coords = list(filter(lambda s: s != "", coords))
    x_start = int(coords[0])
    y_start = int(coords[1])
    x_end = int(coords[2])
    y_end = int(coords[3])
    next_line = Line((x_start, y_start), (x_end, y_end))

    if x_start < x_min:
        x_min = x_start
    if x_end < x_min:
        x_min = x_end

    if y_start < y_min:
        y_min = y_start
    if y_end < y_min:
        y_min = y_end

    if x_start > x_max:
        x_max = x_start
    if x_end > x_max:
        x_max = x_end

    if y_start > y_max:
        y_max = y_start
    if y_end > y_max:
        y_max = y_start

    lines.append(next_line)


out_image = Image.new(mode="RGB", size=(x_max - x_min, y_max - y_min))

draw = ImageDraw.Draw(out_image)
for line in lines:
    draw.line(
        (
            line.start[0] - x_min,
            line.start[1] - y_min,
            line.end[0] - x_min,
            line.end[1] - y_min,
        ),
        fill=255,
    )

out_image.show()

print(len(lines))
print(y_max)
