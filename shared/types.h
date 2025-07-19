#ifndef __SHARED_TYPES_H
#define __SHARED_TYPES_H

/* assuming RV64 ABI */
typedef unsigned char u8;
typedef signed char i8;
typedef unsigned short u16;
typedef short i16;
typedef unsigned int u32;
typedef int i32;
typedef unsigned long u64;
typedef long i64;
typedef u64 usize;
typedef i64 isize;
typedef float f32;
typedef double f64;

/* discourage use of builtin integer types */
#define signed   _Pragma("message \"Use a sized typedef.\"") signed
#define unsigned _Pragma("message \"Use a sized typedef.\"") unsigned
#define short    _Pragma("message \"Use a sized typedef.\"") short
#define int      _Pragma("message \"Use a sized typedef.\"") int
#define long     _Pragma("message \"Use a sized typedef.\"") long
#define float    _Pragma("message \"Use a sized typedef.\"") float
#define double   _Pragma("message \"Use a sized typedef.\"") double

#endif
