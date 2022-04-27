# BNO055用インターフェイス
bno055 -> stm32 -> can -> sokcetcan_interface_node -> this
## CAN ID
| CAN ID |       内容       |
|:------:|:--------------:|
| 0x0312 |  加速度x(double)  |
| 0x0313 |  加速度y(double)  |
| 0x0314 |  加速度z(double)  |
| 0x0322 | ジャイロx(double)  |
| 0x0323 | ジャイロy(double)  |
| 0x0324 | ジャイロz(double)  |
| 0x0332 | quat x(double) |
| 0x0333 | quat y(double) |
| 0x0334 | quat z(double) |