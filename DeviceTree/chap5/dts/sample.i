/dts-v1/;

/ {
	model = "ARM Versatile PB";
	compatible = "ARM Versatile PB";
	#address-cells = <0x01>;
	#size-cells = <0x01>;
	interrupt-parent = <0x01>;

	cpus {
		#address-cells = <0x01>;
		#size-cells = <0x00>;

		cpu@0 {
			compatible = "arm,cortex-a9";
			reg = <0x00>;
		};

		cpu@1 {
			compatible = "arm,cortex-a9";
			reg = <0x01>;
		};
	};

	intc@10140000 {
		compatible = "arm,versatile-vic";
		interrupt-controller;
		#interrupt-cells = <0x01>;
		reg = <0x10140000 0x1000>;
		clear-mask = <0xffffffff>;
		valid-mask = <0xffffffff>;
		phandle = <0x01>;
	};

	serial@101f1000 {
		compatible = "arm,pl011";
		reg = <0x101f1000 0x1000>;
		interrupts = <0x0c>;
	};

	gpio@101e4000 {
		compatible = "arm,pl011";
		reg = <0x101e4000 0x1000>;
		interrupts = <0x06>;
	};

	external-bus@10100000 {
		#address-cells = <0x02>;
		#size-cells = <0x01>;
		ranges = <0x00 0x00 0x10100000 0x10000 0x01 0x00 0x10160000 0x10000>;

		ethernet@0,0 {
			compatible = "arm,smc91c111";
			reg = <0x00 0x00 0x1000>;
			interrupts = <0x07>;
		};

		i2c@1,0 {
			compatible = "arm,i2c-bus";
			reg = <0x01 0x00 0x1000>;
		};
	};
};
