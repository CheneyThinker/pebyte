#pragma once

#ifndef PEBYTE_DEF_H
#define PEBYTE_DEF_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned int   dword;//doubleword
typedef unsigned long  qword;//quadword

// dos_header
#define E_RES_SIZE             4
#define E_RES2_SIZE           10
#define IMAGE_DOS_HEADER_SIZE 64
// dos_header

// dos_stub
#define SKIP_DOS_STUB
// dos_stub

// file_header
//   machine
#define IMAGE_FILE_MACHINE_UNKNOWN   0x0000
#define IMAGE_FILE_MACHINE_AM33      0x01d3
#define IMAGE_FILE_MACHINE_AMD64     0x8664
#define IMAGE_FILE_MACHINE_ARM       0x01c0
#define IMAGE_FILE_MACHINE_ARM64     0xaa64
#define IMAGE_FILE_MACHINE_ARMNT     0x01c4
#define IMAGE_FILE_MACHINE_EBC       0x0ebc
#define IMAGE_FILE_MACHINE_I386      0x014c
#define IMAGE_FILE_MACHINE_IA64      0x0200
#define IMAGE_FILE_MACHINE_M32R      0x9041
#define IMAGE_FILE_MACHINE_MIPS16    0x0266
#define IMAGE_FILE_MACHINE_MIPSFPU   0x0366
#define IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#define IMAGE_FILE_MACHINE_POWERPC   0x01f0
#define IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#define IMAGE_FILE_MACHINE_R4000     0x0166
#define IMAGE_FILE_MACHINE_RISCV32   0x5032
#define IMAGE_FILE_MACHINE_RISCV64   0x5064
#define IMAGE_FILE_MACHINE_RISCV128  0x5128
#define IMAGE_FILE_MACHINE_SH3       0x01a2
#define IMAGE_FILE_MACHINE_SH3DSP    0x01a3
#define IMAGE_FILE_MACHINE_SH4       0x01a6
#define IMAGE_FILE_MACHINE_SH5       0x01a8
#define IMAGE_FILE_MACHINE_THUMB     0x01c2
#define IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
//   machine
//   characteristics
#define IMAGE_FILE_RELOCS_STRIPPED          0x0001
#define IMAGE_FILE_EXECUTABLE_IMAGE         0x0002
#define IMAGE_FILE_LINE_NUMS_STRIPPED       0x0004
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED      0x0008
#define IMAGE_FILE_AGGRESSIVE_WS_TRIM       0x0010
#define IMAGE_FILE_LARGE_ADDRESS_ AWARE     0x0020 //0x0040
#define IMAGE_FILE_BYTES_REVERSED_LO        0x0080
#define IMAGE_FILE_32BIT_MACHINE            0x0100
#define IMAGE_FILE_DEBUG_STRIPPED           0x0200
#define IMAGE_FILE_REMOVABLE_RUN_ FROM_SWAP 0x0400
#define IMAGE_FILE_NET_RUN_FROM_SWAP        0x0800
#define IMAGE_FILE_SYSTEM                   0x1000
#define IMAGE_FILE_DLL                      0x2000
#define IMAGE_FILE_UP_SYSTEM_ONLY           0x4000
#define IMAGE_FILE_BYTES_REVERSED_HI        0x8000
//   characteristics
// file_header

/*
#define LITTLE_ENDIAN

// IMAGE_DOS_HEADER e_magic
#ifdef LITTLE_ENDIAN
  #define IMAGE_DOS_SIGNATURE                 0x5a4d      // MZ
  #define IMAGE_OS2_SIGNATURE                 0x454e      // NE
  #define IMAGE_OS2_SIGNATURE_LE              0x454c      // LE
  #define IMAGE_VXD_SIGNATURE                 0x454c      // LE
#else
  #define IMAGE_DOS_SIGNATURE                 0x4d5a      // MZ
  #define IMAGE_OS2_SIGNATURE                 0x4e45      // NE
  #define IMAGE_OS2_SIGNATURE_LE              0x4c45      // LE
#endif
// IMAGE_DOS_HEADER e_magic

// IMAGE_NT_HEADERS signature
#ifdef LITTLE_ENDIAN
  #define IMAGE_NT_SIGNATURE                  0x00004550  // PE00
#else
  #define IMAGE_NT_SIGNATURE                  0x50450000  // PE00
#endif
// IMAGE_NT_HEADERS signature

// IMAGE_FILE_HEADER characteristics
#define IMAGE_FILE_RELOCS_STRIPPED           0x0001  // Relocation info stripped from file.
#define IMAGE_FILE_EXECUTABLE_IMAGE          0x0002  // File is executable  (i.e. no unresolved externel references).
#define IMAGE_FILE_LINE_NUMS_STRIPPED        0x0004  // Line nunbers stripped from file.
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED       0x0008  // Local symbols stripped from file.
#define IMAGE_FILE_AGGRESIVE_WS_TRIM         0x0010  // Agressively trim working set
#define IMAGE_FILE_LARGE_ADDRESS_AWARE       0x0020  // App can handle >2gb addresses
#define IMAGE_FILE_BYTES_REVERSED_LO         0x0080  // Bytes of machine word are reversed.
#define IMAGE_FILE_32BIT_MACHINE             0x0100  // 32 bit word machine.
#define IMAGE_FILE_DEBUG_STRIPPED            0x0200  // Debugging info stripped from file in .DBG file
#define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP   0x0400  // If Image is on removable media, copy and run from the swap file.
#define IMAGE_FILE_NET_RUN_FROM_SWAP         0x0800  // If Image is on Net, copy and run from the swap file.
#define IMAGE_FILE_SYSTEM                    0x1000  // System File.
#define IMAGE_FILE_DLL                       0x2000  // File is a DLL.
#define IMAGE_FILE_UP_SYSTEM_ONLY            0x4000  // File should only be run on a UP machine
#define IMAGE_FILE_BYTES_REVERSED_HI         0x8000  // Bytes of machine word are reversed.
// IMAGE_FILE_HEADER characteristics

// IMAGE_OPTIONAL_HEADER subSystem
#define IMAGE_SUBSYSTEM_UNKNOWN                  0x0000   // Unknown subsystem.
#define IMAGE_SUBSYSTEM_NATIVE                   0x0001   // Image doesn't require a subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_GUI              0x0002   // Image runs in the Windows GUI subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_CUI              0x0003   // Image runs in the Windows character subsystem.
#define IMAGE_SUBSYSTEM_OS2_CUI                  0x0005   // image runs in the OS/2 character subsystem.
#define IMAGE_SUBSYSTEM_POSIX_CUI                0x0007   // image runs in the Posix character subsystem.
#define IMAGE_SUBSYSTEM_NATIVE_WINDOWS           0x0008   // image is a native Win9x driver.
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI           0x0009   // Image runs in the Windows CE subsystem.
#define IMAGE_SUBSYSTEM_EFI_APPLICATION          0x000a
#define IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  0x000b
#define IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER       0x000c
#define IMAGE_SUBSYSTEM_EFI_ROM                  0x000d
#define IMAGE_SUBSYSTEM_XBOX                     0x000e
#define IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION 0x0010
// IMAGE_OPTIONAL_HEADER subSystem

// IMAGE_OPTIONAL_HEADER dllCharacteristics
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE            0x0040     // DLL can move.
#define IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY         0x0080     // Code Integrity Image
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT               0x0100     // Image is NX compatible
#define IMAGE_DLLCHARACTERISTICS_NO_ISOLATION            0x0200     // Image understands isolation and doesn't want it
#define IMAGE_DLLCHARACTERISTICS_NO_SEH                  0x0400     // Image does not use SEH.  No SE handler may reside in this image
#define IMAGE_DLLCHARACTERISTICS_NO_BIND                 0x0800     // Do not bind this image.
#define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER              0x2000     // Driver uses WDM model
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE   0x8000
// IMAGE_OPTIONAL_HEADER dllCharacteristics

// IMAGE_OPTIONAL_HEADER dataDirectory[index]
#define IMAGE_DIRECTORY_ENTRY_EXPORT          0   // Export Directory
#define IMAGE_DIRECTORY_ENTRY_IMPORT          1   // Import Directory
#define IMAGE_DIRECTORY_ENTRY_RESOURCE        2   // Resource Directory
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION       3   // Exception Directory
#define IMAGE_DIRECTORY_ENTRY_SECURITY        4   // Security Directory
#define IMAGE_DIRECTORY_ENTRY_BASERELOC       5   // Base Relocation Table
#define IMAGE_DIRECTORY_ENTRY_DEBUG           6   // Debug Directory
//      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7   // (X86 usage)
#define IMAGE_DIRECTORY_ENTRY_ARCHITECTURE    7   // Architecture Specific Data
#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR       8   // RVA of GP
#define IMAGE_DIRECTORY_ENTRY_TLS             9   // TLS Directory
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    10   // Load Configuration Directory
#define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   11   // Bound Import Directory in headers
#define IMAGE_DIRECTORY_ENTRY_IAT            12   // Import Address Table
#define IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   13   // Delay Load Import Descriptors
#define IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14   // COM Runtime descriptor
// IMAGE_OPTIONAL_HEADER dataDirectory[index]

// IMAGE_SECTION_HEADER characteristics
#define IMAGE_SCN_TYPE_NO_PAD                0x00000008  // Reserved.
#define IMAGE_SCN_CNT_CODE                   0x00000020  // Section contains code.
#define IMAGE_SCN_CNT_INITIALIZED_DATA       0x00000040  // Section contains initialized data.
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA     0x00000080  // Section contains uninitialized data.
#define IMAGE_SCN_LNK_OTHER                  0x00000100  // Reserved.
#define IMAGE_SCN_LNK_INFO                   0x00000200  // Section contains comments or some other type of information.
#define IMAGE_SCN_LNK_REMOVE                 0x00000800  // Section contents will not become part of image.
#define IMAGE_SCN_LNK_COMDAT                 0x00001000  // Section contents comdat.
#define IMAGE_SCN_NO_DEFER_SPEC_EXC          0x00004000  // Reset speculative exceptions handling bits in the TLB entries for this section.
#define IMAGE_SCN_GPREL                      0x00008000  // Section content can be accessed relative to GP
#define IMAGE_SCN_MEM_FARDATA                0x00008000
#define IMAGE_SCN_MEM_PURGEABLE              0x00020000
#define IMAGE_SCN_MEM_16BIT                  0x00020000
#define IMAGE_SCN_MEM_LOCKED                 0x00040000
#define IMAGE_SCN_MEM_PRELOAD                0x00080000
#define IMAGE_SCN_ALIGN_1BYTES               0x00100000  //
#define IMAGE_SCN_ALIGN_2BYTES               0x00200000  //
#define IMAGE_SCN_ALIGN_4BYTES               0x00300000  //
#define IMAGE_SCN_ALIGN_8BYTES               0x00400000  //
#define IMAGE_SCN_ALIGN_16BYTES              0x00500000  // Default alignment if no others are specified.
#define IMAGE_SCN_ALIGN_32BYTES              0x00600000  //
#define IMAGE_SCN_ALIGN_64BYTES              0x00700000  //
#define IMAGE_SCN_ALIGN_128BYTES             0x00800000  //
#define IMAGE_SCN_ALIGN_256BYTES             0x00900000  //
#define IMAGE_SCN_ALIGN_512BYTES             0x00A00000  //
#define IMAGE_SCN_ALIGN_1024BYTES            0x00B00000  //
#define IMAGE_SCN_ALIGN_2048BYTES            0x00C00000  //
#define IMAGE_SCN_ALIGN_4096BYTES            0x00D00000  //
#define IMAGE_SCN_ALIGN_8192BYTES            0x00E00000  //
#define IMAGE_SCN_ALIGN_MASK                 0x00F00000
#define IMAGE_SCN_LNK_NRELOC_OVFL            0x01000000  // Section contains extended relocations.
#define IMAGE_SCN_MEM_DISCARDABLE            0x02000000  // Section can be discarded.
#define IMAGE_SCN_MEM_NOT_CACHED             0x04000000  // Section is not cachable.
#define IMAGE_SCN_MEM_NOT_PAGED              0x08000000  // Section is not pageable.
#define IMAGE_SCN_MEM_SHARED                 0x10000000  // Section is shareable.
#define IMAGE_SCN_MEM_EXECUTE                0x20000000  // Section is executable.
#define IMAGE_SCN_MEM_READ                   0x40000000  // Section is readable.
#define IMAGE_SCN_MEM_WRITE                  0x80000000  // Section is writeable.
// IMAGE_SECTION_HEADER characteristics

/*
#ifdef LITTLE_ENDIAN
  #define swap_word(origin) ((origin << 8 & 0XFF00) | (origin >> 8 & 0X00FF))
  #define swap_dword(origin) ((origin << 24 & 0XFF000000) | (origin <<  8 & 0X00FF0000) | (origin >> 24 & 0X000000FF) | (origin >>  8 & 0X0000FF00))
  #define swap_ddword(origin) ((origin << 56 & 0XFF00000000000000) | (origin << 48 & 0X00FF000000000000) | (origin << 24 & 0X0000FF0000000000) | (origin <<  8 & 0X000000FF00000000) | (origin >> 56 & 0X00000000000000FF) | (origin >> 48 & 0X000000000000FF00) | (origin >> 24 & 0X0000000000FF0000) | (origin >> 8 & 0X000000000FF000000))
#else
  #define swap_word(origin) origin
  #define swap_dword(origin) origin
  #define swap_ddword(origin) origin
#endif
typedef union _ENDIAN {
  char  byte;
  short dword;
} ENDIAN;
ENDIAN endian;
endian.dword = 0x1234;
if (endian.byte == 0x12) {//BIG_ENDIAN
} else if (endian.byte == 0x34) {//LITTLE_ENDIAN
}
*/

#endif
