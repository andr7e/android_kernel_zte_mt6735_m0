#script compile kernel by andr7e

toolchain="$HOME/kernel_build/aarch64-linux-android-4.9/bin/aarch64-linux-android-"
source_path=`pwd`
kernel_path="$source_path/android_kernel_zte_mt6735_m0"

output_path="$source_path/out"


export CROSS_COMPILE=$toolchain

export ARCH=arm64
export TARGET_ARCH=arm64

build_kernel()
{ 
	cd "$kernel_path"

	if [ ! -d "$output_path" ]; then
	   mkdir "$output_path"
	fi

	echo "${output_path}"

	makeflags+=" O=${output_path}"

	#make clean

	make ${makeflags} cyanogenmod_ztet660_defconfig

	make ${makeflags} -j4 Image.gz-dtb
}

build_kernel
