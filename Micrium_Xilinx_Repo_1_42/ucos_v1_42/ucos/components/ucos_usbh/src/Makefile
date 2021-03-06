#########################################################################################################
#                                           MICRIUM XSDK REPOSITORY
#                           (c) Copyright 2014-2015; Micrium, Inc.; Weston, FL
#
#               All rights reserved.  Protected by international copyright laws.
#########################################################################################################

COMPILER=
CP=cp
COMPILER_FLAGS=
EXTRA_COMPILER_FLAGS=
LIB=libucos.a

CC_FLAGS = $(COMPILER_FLAGS)
ECC_FLAGS = $(EXTRA_COMPILER_FLAGS)

RELEASEDIR=../../../lib
INCLUDEDIR=../../../include
INCLUDES=-I./. -I${INCLUDEDIR}

OUTS = *.o

include ../../../include/Makefile_def.inc

DIST_LIB=libucusbh-${UCOS_OS}-${UCOS_ARCH}.a

LIBSOURCES:=usbh_hc_cfg.c \
            uC-USB-Host/Source/usbh_class.c \
            uC-USB-Host/Source/usbh_core.c \
            uC-USB-Host/Source/usbh_hub.c \
            uC-USB-Host/HCD/EHCI/usbh_hcd_ehci.c \
            uC-USB-Host/OS/${UCOS_DIR_NAME}/usbh_os.c \
            uC-USB-Host/Class/CDC/usbh_cdc.c \
            uC-USB-Host/Class/CDC/ACM/usbh_acm.c \
            uC-USB-Host/Class/FTDI/usbh_ftdi.c \
            uC-USB-Host/Class/HID/usbh_hid.c \
            uC-USB-Host/Class/HID/usbh_hidparser.c \
            uC-USB-Host/Class/MSC/usbh_msc.c
            
BSPSOURCES= bsp/usbh_bsp_zynq_ehci.c
           

INCLUDEFILES:=usbh_cfg.h \
              usbh_hc_cfg.h \
              bsp/usbh_bsp_zynq_ehci.h \
              
              
ifeq (${strip ${UCOS_USBH_SRC_BASE}},)
OBJECTS =
else
OBJECTS =	$(addsuffix .o, $(basename ${LIBSOURCES}))
endif

BSPOBJECTS = $(addsuffix .o, $(basename ${BSPSOURCES}))

libs: banner lib_copy ucos_final_libs bsp clean

%.o: %.c
	${MKDIR} -p $(@D)
	${COMPILER} $(CC_FLAGS) $(ECC_FLAGS) $(INCLUDES) -o $@ $<

%.o: %.S
	${MKDIR} -p $(@D)
	${COMPILER} $(CC_FLAGS) $(ECC_FLAGS) $(INCLUDES) -o $@ $<

banner:
	echo "Compiling uC/USB-Host"
	
lib_copy:
ifeq (${strip ${UCOS_USBH_SRC_BASE}},)
	echo "uC/USB-Host sources not found, using pre-compiled library"
	${CP} ${UCOS_LIB_LOC}/${DIST_LIB} ${RELEASEDIR}/
	touch ${RELEASEDIR}/${DIST_LIB}
else
	echo "Building uC/USB-Host from sources at ${UCOS_USBH_SRC_BASE}"
endif

${RELEASEDIR}/${DIST_LIB}: ${OBJECTS}
		$(ARCHIVER) -cr ${RELEASEDIR}/${DIST_LIB} ${OBJECTS}
		
ucos_final_libs: ${RELEASEDIR}/${DIST_LIB}
		rm -rf ${OBJECTS}
		$(ARCHIVER) -x ${RELEASEDIR}/${DIST_LIB}
		$(ARCHIVER) -r ${RELEASEDIR}/${LIB} *.o
		rm -rf *.o
		
bsp: ${BSPOBJECTS}
	$(ARCHIVER) -r ${RELEASEDIR}/${LIB} ${BSPOBJECTS}

.PHONY: include
include:
	${CP} ${INCLUDEFILES} ${INCLUDEDIR}
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Source/usbh_class.h ${INCLUDEDIR}/Source
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Source/usbh_core.h ${INCLUDEDIR}/Source
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Source/usbh_err.h ${INCLUDEDIR}/Source
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Source/usbh_hub.h ${INCLUDEDIR}/Source
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Source/usbh_os.h ${INCLUDEDIR}/Source
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/HCD/EHCI/usbh_hcd_ehci.h ${INCLUDEDIR}/HCD/EHCI
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Class/CDC/usbh_cdc.h ${INCLUDEDIR}/Class/CDC
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Class/CDC/ACM/usbh_acm.h ${INCLUDEDIR}/Class/CDC/ACM
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Class/FTDI/usbh_ftdi.h ${INCLUDEDIR}/Class/FTDI
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Class/HID/usbh_hid.h ${INCLUDEDIR}/Class/HID
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Class/HID/usbh_hidparser.h ${INCLUDEDIR}/Class/HID
	${CP} ${UCOS_SRC_BASE}/uC-USB-Host/Class/MSC/usbh_msc.h ${INCLUDEDIR}/Class/MSC
	
clean:
	rm -rf ${OBJECTS}

