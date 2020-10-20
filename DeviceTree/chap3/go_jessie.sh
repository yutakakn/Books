qemu-system-arm \
-M raspi2 \
-append "rw earlyprintk loglevel=8 console=ttyAMA0,115200 dwc_otg.lpm_enable=0 root=/dev/mmcblk0p2" \
-cpu arm1176 \
-dtb bcm2709-rpi-2-b.dtb \
-sd ../2016-05-27-raspbian-jessie.img \
-kernel kernel7.img \
-m 1G \
-smp 4 \
-serial stdio \
-net nic -net user,hostfwd=tcp::10022-:22

