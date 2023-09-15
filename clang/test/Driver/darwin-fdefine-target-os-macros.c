// RUN: %clang -### --target=arm64-apple-darwin %s 2>&1 | FileCheck %s --check-prefix=DEFAULT-OPTION

// RUN: %clang -dM -E --target=arm64-apple-macos %s 2>&1 \
// RUN: | FileCheck %s -DMAC=1         \
// RUN:                -DOSX=1         \
// RUN:                -DIPHONE=0      \
// RUN:                -DIOS=0         \
// RUN:                -DTV=0          \
// RUN:                -DWATCH=0       \
// RUN:                -DDRIVERKIT=0   \
// RUN:                -DMACCATALYST=0 \
// RUN:                -DEMBEDDED=0    \
// RUN:                -DSIMULATOR=0

// RUN: %clang -dM -E --target=arm64-apple-ios %s 2>&1 \
// RUN: | FileCheck %s -DMAC=1         \
// RUN:                -DOSX=0         \
// RUN:                -DIPHONE=1      \
// RUN:                -DIOS=1         \
// RUN:                -DTV=0          \
// RUN:                -DWATCH=0       \
// RUN:                -DDRIVERKIT=0   \
// RUN:                -DMACCATALYST=0 \
// RUN:                -DEMBEDDED=1    \
// RUN:                -DSIMULATOR=0

// RUN: %clang -dM -E --target=arm64-apple-ios-macabi %s 2>&1 \
// RUN: | FileCheck %s -DMAC=1         \
// RUN:                -DOSX=0         \
// RUN:                -DIPHONE=1      \
// RUN:                -DIOS=1         \
// RUN:                -DTV=0          \
// RUN:                -DWATCH=0       \
// RUN:                -DDRIVERKIT=0   \
// RUN:                -DMACCATALYST=1 \
// RUN:                -DEMBEDDED=0    \
// RUN:                -DSIMULATOR=0

// RUN: %clang -dM -E --target=arm64-apple-ios-simulator %s 2>&1 \
// RUN: | FileCheck %s -DMAC=1         \
// RUN:                -DOSX=0         \
// RUN:                -DIPHONE=1      \
// RUN:                -DIOS=1         \
// RUN:                -DTV=0          \
// RUN:                -DWATCH=0       \
// RUN:                -DDRIVERKIT=0   \
// RUN:                -DMACCATALYST=0 \
// RUN:                -DEMBEDDED=0    \
// RUN:                -DSIMULATOR=1

// RUN: %clang -dM -E --target=arm64-apple-tvos %s 2>&1 \
// RUN: | FileCheck %s -DMAC=1         \
// RUN:                -DOSX=0         \
// RUN:                -DIPHONE=1      \
// RUN:                -DIOS=0         \
// RUN:                -DTV=1          \
// RUN:                -DWATCH=0       \
// RUN:                -DDRIVERKIT=0   \
// RUN:                -DMACCATALYST=0 \
// RUN:                -DEMBEDDED=1    \
// RUN:                -DSIMULATOR=0

// RUN: %clang -dM -E --target=arm64-apple-tvos-simulator %s 2>&1 \
// RUN: | FileCheck %s -DMAC=1         \
// RUN:                -DOSX=0         \
// RUN:                -DIPHONE=1      \
// RUN:                -DIOS=0         \
// RUN:                -DTV=1          \
// RUN:                -DWATCH=0       \
// RUN:                -DDRIVERKIT=0   \
// RUN:                -DMACCATALYST=0 \
// RUN:                -DEMBEDDED=0    \
// RUN:                -DSIMULATOR=1

// RUN: %clang -dM -E --target=arm64-apple-watchos %s 2>&1 \
// RUN: | FileCheck %s -DMAC=1         \
// RUN:                -DOSX=0         \
// RUN:                -DIPHONE=1      \
// RUN:                -DIOS=0         \
// RUN:                -DTV=0          \
// RUN:                -DWATCH=1       \
// RUN:                -DDRIVERKIT=0   \
// RUN:                -DMACCATALYST=0 \
// RUN:                -DEMBEDDED=1    \
// RUN:                -DSIMULATOR=0

// RUN: %clang -dM -E --target=arm64-apple-watchos-simulator %s 2>&1 \
// RUN: | FileCheck %s -DMAC=1         \
// RUN:                -DOSX=0         \
// RUN:                -DIPHONE=1      \
// RUN:                -DIOS=0         \
// RUN:                -DTV=0          \
// RUN:                -DWATCH=1       \
// RUN:                -DDRIVERKIT=0   \
// RUN:                -DMACCATALYST=0 \
// RUN:                -DEMBEDDED=0    \
// RUN:                -DSIMULATOR=1

// RUN: %clang -dM -E --target=arm64-apple-driverkit %s 2>&1 \
// RUN: | FileCheck %s -DMAC=1         \
// RUN:                -DOSX=0         \
// RUN:                -DIPHONE=0      \
// RUN:                -DIOS=0         \
// RUN:                -DTV=0          \
// RUN:                -DWATCH=0       \
// RUN:                -DDRIVERKIT=1   \
// RUN:                -DMACCATALYST=0 \
// RUN:                -DEMBEDDED=0    \
// RUN:                -DSIMULATOR=0

// DEFAULT-OPTION: "-fdefine-target-os-macros"

// CHECK-DAG: #define TARGET_OS_MAC [[MAC]]
// CHECK-DAG: #define TARGET_OS_OSX [[OSX]]
// CHECK-DAG: #define TARGET_OS_IPHONE [[IPHONE]]
// CHECK-DAG: #define TARGET_OS_IOS [[IOS]]
// CHECK-DAG: #define TARGET_OS_TV [[TV]]
// CHECK-DAG: #define TARGET_OS_WATCH [[WATCH]]
// CHECK-DAG: #define TARGET_OS_DRIVERKIT [[DRIVERKIT]]
// CHECK-DAG: #define TARGET_OS_MACCATALYST [[MACCATALYST]]
// CHECK-DAG: #define TARGET_OS_SIMULATOR [[SIMULATOR]]
// Deprecated
// CHECK-DAG: #define TARGET_OS_EMBEDDED [[EMBEDDED]]
// CHECK-DAG: #define TARGET_OS_NANO [[WATCH]]
// CHECK-DAG: #define TARGET_IPHONE_SIMULATOR [[SIMULATOR]]
// CHECK-DAG: #define TARGET_OS_UIKITFORMAC [[MACCATALYST]]
// Non-darwin OSes
// CHECK-DAG: #define TARGET_OS_WIN32 0
// CHECK-DAG: #define TARGET_OS_WINDOWS 0
// CHECK-DAG: #define TARGET_OS_LINUX 0
// CHECK-DAG: #define TARGET_OS_UNIX 0
