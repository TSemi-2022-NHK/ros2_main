# R1上下角度調整用用インターフェイス
stepper moter -> stm32 -> can -> sokcetcan_interface_node -> this
## CAN ID
| CAN ID |   内容   |                  形式                   |
|:------:|:------:|:-------------------------------------:|
| 0x0501 | 角度指定命令 | (2)[モード(0なら原点復帰、1なら角度に設定)], [設定する角度]] |