#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef float float32;
typedef double float64;

typedef size_t usize;
typedef void *universal; // anyref

typedef int flag;
typedef int boolean;

enum {
	False = 0,
	True = 1
};

#define Null NULL

typedef void (*callback)(void);

#define min(_v0, _v1) (_v0 < _v1 ? _v0 : _v1)
#define max(_v0, _v1) (_v0 > _v1 ? _v0 : _v1)
#define clamp(_v, _min, _max) (_v < _min ? _min : _v > _max ? _max : _v)
