cmd_arch/arm/boot/dts/versatile-pb.dtb := mkdir -p arch/arm/boot/dts/ ; gcc -E -Wp,-MD,arch/arm/boot/dts/.versatile-pb.dtb.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm/boot/dts/.versatile-pb.dtb.dts.tmp arch/arm/boot/dts/versatile-pb.dts ; ./scripts/dtc/dtc -O dtb -o arch/arm/boot/dts/versatile-pb.dtb -b 0 -iarch/arm/boot/dts/ -i./scripts/dtc/include-prefixes -Wno-unit_address_vs_reg -Wno-unit_address_format -Wno-gpios_property -Wno-avoid_unnecessary_addr_size -Wno-alias_paths -Wno-graph_child_address -Wno-simple_bus_reg -Wno-unique_unit_address -Wno-pci_device_reg  -d arch/arm/boot/dts/.versatile-pb.dtb.d.dtc.tmp arch/arm/boot/dts/.versatile-pb.dtb.dts.tmp ; cat arch/arm/boot/dts/.versatile-pb.dtb.d.pre.tmp arch/arm/boot/dts/.versatile-pb.dtb.d.dtc.tmp > arch/arm/boot/dts/.versatile-pb.dtb.d

source_arch/arm/boot/dts/versatile-pb.dtb := arch/arm/boot/dts/versatile-pb.dts

deps_arch/arm/boot/dts/versatile-pb.dtb := \
  arch/arm/boot/dts/versatile-ab.dts \

arch/arm/boot/dts/versatile-pb.dtb: $(deps_arch/arm/boot/dts/versatile-pb.dtb)

$(deps_arch/arm/boot/dts/versatile-pb.dtb):
