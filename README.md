### Parallel Port Pinout

pin | name (jj) | name (es) | direction | desc (es) | desc (jj)
----|----------|-----------|----------|----------|---------
1 | 5v
2 | 5v
3 | 5v
4 | 5v
5 | /MODEMCS | G2_MDMCSN | Output | Modem chip select | modem enable
6 | /IRQA | G2_IRMDMN | Input | Modem interruption | modem / lan adapter irq
7 | ??? | G2_RQDEVN | Input | Debugger /TransferRequest
8 | ??? | G2_RQEX1N | Input | External Device1 /TransferRequest
9 | ??? | G2_RQEX0N | Input | External Device0 /TransferRequest
10 | gnd
11 | gnd
12 | gnd
13 | /IRQB | G2_IREXTN | Input | External device interrupt | BBA irq
14 | /LBE or /WR | G2_BLN | output | Lowest data(G2_AD[7:0]) valid | lower byte enable or modem write
15 | ??? | G2_STN | Input | /Stop
16 | /UBE or /RD | G2_BHN | output | Highest data(G2_AD[15:8]) valid | upper byte enable or modem read
17 | 3.3v
18 | 3.3v
19 | 3.3v
20 | /BTB | G2_DSN | In/output | /DeviceSelect | input, access time / burst xfer
21 | /AEN |  G2_FRN | output | Frame signal | Address enable / bus cycle start
22 | /BTA | G2_TRN | input | /TargetReady | access time control / burst xfer
23 | gnd
24 | gnd
25-40 | AD[15:0] | G2_AD[15:0] | In/output | Address/data multiplex bus | same
41 | gnd
42 | gnd
43 | CLK | G2_CLK | output | G2bus/clock | system clock
44 | gnd
45 | gnd
46 | /RESET | G_RST | output | reset | system reset
47 | gnd
48 | gnd
49 | ??? | midi_out
50 | ??? | midi_in

### Other G2 signals
Pin | name (es) | direction | desc (es)
--|--|--|--
??? | G2_RQAICN | Input | AICA /TransferRequest
??? | G2_IRAICN | Input | AICA interruption

sources: https://web.archive.org/web/20221206012741/http://jj1odm.qp.land.to/g2bus.php, https://www.dreamcast.es/infusions/forum/viewthread.php?thread_id=21&rowstart=40, https://gamingdoc.org/technical-documentation/consoles/sega-dreamcast/independent/integrated-circuits/holly-graphics-engine/
