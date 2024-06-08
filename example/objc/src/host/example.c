#include "w2c2_base.h"

#include "example.h"

const U8 d0[]={
0x2d,0x2b,0x20,0x20,0x20,0x30,0x58,0x30,0x78,0x0,0x2d,0x30,0x58,0x2b,0x30,0x58,0x20,0x30,0x58,0x2d,0x30,0x78,0x2b,0x30,0x78,0x20,0x30,0x78,0x0,0x6e,0x61,0x6e,0x0,0x53,0x74,0x72,0x69,0x6e,0x67,0x0,0x69,0x6e,0x66,0x0,0x4e,0x41,0x4e,0x0,0x49,0x4e,0x46,0x0,0x2e,0x0,0x28,0x6e,0x75,0x6c,0x6c,0x29,0x0,0x48,0x65,0x6c,0x6c,0x6f,0x2c,0x20,0x77,0x6f,0x72,0x6c,0x64,0x21,0x0,0x63,0x6c,0x69,0x65,0x6e,0x74,0x3a,0x20,0x65,0x71,0x75,0x61,0x6c,0x3a,0x20,0x25,0x64,0xa,0x0,0x53,0x75,0x70,0x70,0x6f,0x72,0x74,0x20,0x66,0x6f,0x72,0x20,0x66,0x6f,0x72,0x6d,0x61,0x74,0x74,0x69,0x6e,0x67,0x20,0x6c,0x6f,0x6e,0x67,0x20,0x64,0x6f,0x75,0x62,0x6c,0x65,0x20,0x76,0x61,0x6c,0x75,0x65,0x73,0x20,0x69,0x73,0x20,0x63,0x75,0x72,0x72,0x65,0x6e,0x74,0x6c,0x79,0x20,0x64,0x69,0x73,0x61,0x62,0x6c,0x65,0x64,0x2e,0xa,0x54,0x6f,0x20,0x65,0x6e,0x61,0x62,0x6c,0x65,0x20,0x69,0x74,0x2c,0x20,0x61,0x64,0x64,0x20,0x2d,0x6c,0x63,0x2d,0x70,0x72,0x69,0x6e,0x74,0x73,0x63,0x61,0x6e,0x2d,0x6c,0x6f,0x6e,0x67,0x2d,0x64,0x6f,0x75,0x62,0x6c,0x65,0x20,0x74,0x6f,0x20,0x74,0x68,0x65,0x20,0x6c,0x69,0x6e,0x6b,0x20,0x63,0x6f,0x6d,0x6d,0x61,0x6e,0x64,0x2e,0xa,0x0,0x53,0x75,0x63,0x63,0x65,0x73,0x73,0x0,0x49,0x6c,0x6c,0x65,0x67,0x61,0x6c,0x20,0x62,0x79,0x74,0x65,0x20,0x73,0x65,0x71,0x75,0x65,0x6e,0x63,0x65,0x0,0x44,0x6f,0x6d,0x61,0x69,0x6e,0x20,0x65,0x72,0x72,0x6f,0x72,0x0,0x52,0x65,0x73,0x75,0x6c,0x74,0x20,0x6e,0x6f,0x74,0x20,0x72,0x65,0x70,0x72,0x65,0x73,0x65,0x6e,0x74,0x61,0x62,0x6c,0x65,0x0,0x4e,0x6f,0x74,0x20,0x61,0x20,0x74,0x74,0x79,0x0,0x50,0x65,0x72,0x6d,0x69,0x73,0x73,0x69,0x6f,0x6e,0x20,0x64,0x65,0x6e,0x69,0x65,0x64,0x0,0x4f,0x70,0x65,0x72,0x61,0x74,0x69,0x6f,0x6e,0x20,0x6e,0x6f,0x74,0x20,0x70,0x65,0x72,0x6d,0x69,0x74,0x74,0x65,0x64,0x0,0x4e,0x6f,0x20,0x73,0x75,0x63,0x68,0x20,0x66,0x69,0x6c,0x65,0x20,0x6f,0x72,0x20,0x64,0x69,0x72,0x65,0x63,0x74,0x6f,0x72,0x79,0x0,0x4e,0x6f,0x20,0x73,0x75,0x63,0x68,0x20,0x70,0x72,0x6f,0x63,0x65,0x73,0x73,0x0,0x46,0x69,0x6c,0x65,0x20,0x65,0x78,0x69,0x73,0x74,0x73,0x0,0x56,0x61,0x6c,0x75,0x65,0x20,0x74,0x6f,0x6f,0x20,0x6c,0x61,0x72,0x67,0x65,0x20,0x66,0x6f,0x72,0x20,0x64,0x61,0x74,0x61,0x20,0x74,0x79,0x70,0x65,0x0,0x4e,0x6f,0x20,0x73,0x70,0x61,0x63,0x65,0x20,0x6c,0x65,0x66,0x74,0x20,0x6f,0x6e,0x20,0x64,0x65,0x76,0x69,0x63,0x65,0x0,0x4f,0x75,0x74,0x20,0x6f,0x66,0x20,0x6d,0x65,0x6d,0x6f,0x72,0x79,0x0,0x52,0x65,0x73,0x6f,0x75,0x72,0x63,0x65,0x20,0x62,0x75,0x73,0x79,0x0,0x49,0x6e,0x74,0x65,0x72,0x72,0x75,0x70,0x74,0x65,0x64,0x20,0x73,0x79,0x73,0x74,0x65,0x6d,0x20,0x63,0x61,0x6c,0x6c,0x0,0x52,0x65,0x73,0x6f,0x75,0x72,0x63,0x65,0x20,0x74,0x65,0x6d,0x70,0x6f,0x72,0x61,0x72,0x69,0x6c,0x79,0x20,0x75,0x6e,0x61,0x76,0x61,0x69,0x6c,0x61,0x62,0x6c,0x65,0x0,0x49,0x6e,0x76,0x61,0x6c,0x69,0x64,0x20,0x73,0x65,0x65,0x6b,0x0,0x43,0x72,0x6f,0x73,0x73,0x2d,0x64,0x65,0x76,0x69,0x63,0x65,0x20,0x6c,0x69,0x6e,0x6b,0x0,0x52,0x65,0x61,0x64,0x2d,0x6f,0x6e,0x6c,0x79,0x20,0x66,0x69,0x6c,0x65,0x20,0x73,0x79,0x73,0x74,0x65,0x6d,0x0,0x44,0x69,0x72,0x65,0x63,0x74,0x6f,0x72,0x79,0x20,0x6e,0x6f,0x74,0x20,0x65,0x6d,0x70,0x74,0x79,0x0,0x43,0x6f,0x6e,0x6e,0x65,0x63,0x74,0x69,0x6f,0x6e,0x20,0x72,0x65,0x73,0x65,0x74,0x20,0x62,0x79,0x20,0x70,0x65,0x65,0x72,0x0,0x4f,0x70,0x65,0x72,0x61,0x74,0x69,0x6f,0x6e,0x20,0x74,0x69,0x6d,0x65,0x64,0x20,0x6f,0x75,0x74,0x0,0x43,0x6f,0x6e,0x6e,0x65,0x63,0x74,0x69,0x6f,0x6e,0x20,0x72,0x65,0x66,0x75,0x73,0x65,0x64,0x0,0x48,0x6f,0x73,0x74,0x20,0x69,0x73,0x20,0x75,0x6e,0x72,0x65,0x61,0x63,0x68,0x61,0x62,0x6c,0x65,0x0,0x41,0x64,0x64,0x72,0x65,0x73,0x73,0x20,0x69,0x6e,0x20,0x75,0x73,0x65,0x0,0x42,0x72,0x6f,0x6b,0x65,0x6e,0x20,0x70,0x69,0x70,0x65,0x0,0x49,0x2f,0x4f,0x20,0x65,0x72,0x72,0x6f,0x72,0x0,0x4e,0x6f,0x20,0x73,0x75,0x63,0x68,0x20,0x64,0x65,0x76,0x69,0x63,0x65,0x20,0x6f,0x72,0x20,0x61,0x64,0x64,0x72,0x65,0x73,0x73,0x0,0x4e,0x6f,0x20,0x73,0x75,0x63,0x68,0x20,0x64,0x65,0x76,0x69,0x63,0x65,0x0,0x4e,0x6f,0x74,0x20,0x61,0x20,0x64,0x69,0x72,0x65,0x63,0x74,0x6f,0x72,0x79,0x0,0x49,0x73,0x20,0x61,0x20,0x64,0x69,0x72,0x65,0x63,0x74,0x6f,0x72,0x79,0x0,0x54,0x65,0x78,0x74,0x20,0x66,0x69,0x6c,0x65,0x20,0x62,0x75,0x73,0x79,0x0,0x45,0x78,0x65,0x63,0x20,0x66,0x6f,0x72,0x6d,0x61,0x74,0x20,0x65,0x72,0x72,0x6f,0x72,0x0,0x49,0x6e,0x76,0x61,0x6c,0x69,0x64,0x20,0x61,0x72,0x67,0x75,0x6d,0x65,0x6e,0x74,0x0,0x41,0x72,0x67,0x75,0x6d,0x65,0x6e,0x74,0x20,0x6c,0x69,0x73,0x74,0x20,0x74,0x6f,0x6f,0x20,0x6c,0x6f,0x6e,0x67,0x0,0x53,0x79,0x6d,0x62,0x6f,0x6c,0x69,0x63,0x20,0x6c,0x69,0x6e,0x6b,0x20,0x6c,0x6f,0x6f,0x70,0x0,0x46,0x69,0x6c,0x65,0x6e,0x61,0x6d,0x65,0x20,0x74,0x6f,0x6f,0x20,0x6c,0x6f,0x6e,0x67,0x0,0x54,0x6f,0x6f,0x20,0x6d,0x61,0x6e,0x79,0x20,0x6f,0x70,0x65,0x6e,0x20,0x66,0x69,0x6c,0x65,0x73,0x20,0x69,0x6e,0x20,0x73,0x79,0x73,0x74,0x65,0x6d,0x0,0x4e,0x6f,0x20,0x66,0x69,0x6c,0x65,0x20,0x64,0x65,0x73,0x63,0x72,0x69,0x70,0x74,0x6f,0x72,0x73,0x20,0x61,0x76,0x61,0x69,0x6c,0x61,0x62,0x6c,0x65,0x0,0x42,0x61,0x64,0x20,0x66,0x69,0x6c,0x65,0x20,0x64,0x65,0x73,0x63,0x72,0x69,0x70,0x74,0x6f,0x72,0x0,0x4e,0x6f,0x20,0x63,0x68,0x69,0x6c,0x64,0x20,0x70,0x72,0x6f,0x63,0x65,0x73,0x73,0x0,0x42,0x61,0x64,0x20,0x61,0x64,0x64,0x72,0x65,0x73,0x73,0x0,0x46,0x69,0x6c,0x65,0x20,0x74,0x6f,0x6f,0x20,0x6c,0x61,0x72,0x67,0x65,0x0,0x54,0x6f,0x6f,0x20,0x6d,0x61,0x6e,0x79,0x20,0x6c,0x69,0x6e,0x6b,0x73,0x0,0x4e,0x6f,0x20,0x6c,0x6f,0x63,0x6b,0x73,0x20,0x61,0x76,0x61,0x69,0x6c,0x61,0x62,0x6c,0x65,0x0,0x52,0x65,0x73,0x6f,0x75,0x72,0x63,0x65,0x20,0x64,0x65,0x61,0x64,0x6c,0x6f,0x63,0x6b,0x20,0x77,0x6f,0x75,0x6c,0x64,0x20,0x6f,0x63,0x63,0x75,0x72,0x0,0x53,0x74,0x61,0x74,0x65,0x20,0x6e,0x6f,0x74,0x20,0x72,0x65,0x63,0x6f,0x76,0x65,0x72,0x61,0x62,0x6c,0x65,0x0,0x50,0x72,0x65,0x76,0x69,0x6f,0x75,0x73,0x20,0x6f,0x77,0x6e,0x65,0x72,0x20,0x64,0x69,0x65,0x64,0x0,0x4f,0x70,0x65,0x72,0x61,0x74,0x69,0x6f,0x6e,0x20,0x63,0x61,0x6e,0x63,0x65,0x6c,0x65,0x64,0x0,0x46,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x20,0x6e,0x6f,0x74,0x20,0x69,0x6d,0x70,0x6c,0x65,0x6d,0x65,0x6e,0x74,0x65,0x64,0x0,0x4e,0x6f,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x20,0x6f,0x66,0x20,0x64,0x65,0x73,0x69,0x72,0x65,0x64,0x20,0x74,0x79,0x70,0x65,0x0,0x49,0x64,0x65,0x6e,0x74,0x69,0x66,0x69,0x65,0x72,0x20,0x72,0x65,0x6d,0x6f,0x76,0x65,0x64,0x0,0x4c,0x69,0x6e,0x6b,0x20,0x68,0x61,0x73,0x20,0x62,0x65,0x65,0x6e,0x20,0x73,0x65,0x76,0x65,0x72,0x65,0x64,0x0,0x50,0x72,0x6f,0x74,0x6f,0x63,0x6f,0x6c,0x20,0x65,0x72,0x72,0x6f,0x72,0x0,0x42,0x61,0x64,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x0,0x4e,0x6f,0x74,0x20,0x61,0x20,0x73,0x6f,0x63,0x6b,0x65,0x74,0x0,0x44,0x65,0x73,0x74,0x69,0x6e,0x61,0x74,0x69,0x6f,0x6e,0x20,0x61,0x64,0x64,0x72,0x65,0x73,0x73,0x20,0x72,0x65,0x71,0x75,0x69,0x72,0x65,0x64,0x0,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x20,0x74,0x6f,0x6f,0x20,0x6c,0x61,0x72,0x67,0x65,0x0,0x50,0x72,0x6f,0x74,0x6f,0x63,0x6f,0x6c,0x20,0x77,0x72,0x6f,0x6e,0x67,0x20,0x74,0x79,0x70,0x65,0x20,0x66,0x6f,0x72,0x20,0x73,0x6f,0x63,0x6b,0x65,0x74,0x0,0x50,0x72,0x6f,0x74,0x6f,0x63,0x6f,0x6c,0x20,0x6e,0x6f,0x74,0x20,0x61,0x76,0x61,0x69,0x6c,0x61,0x62,0x6c,0x65,0x0,0x50,0x72,0x6f,0x74,0x6f,0x63,0x6f,0x6c,0x20,0x6e,0x6f,0x74,0x20,0x73,0x75,0x70,0x70,0x6f,0x72,0x74,0x65,0x64,0x0,0x4e,0x6f,0x74,0x20,0x73,0x75,0x70,0x70,0x6f,0x72,0x74,0x65,0x64,0x0,0x41,0x64,0x64,0x72,0x65,0x73,0x73,0x20,0x66,0x61,0x6d,0x69,0x6c,0x79,0x20,0x6e,0x6f,0x74,0x20,0x73,0x75,0x70,0x70,0x6f,0x72,0x74,0x65,0x64,0x20,0x62,0x79,0x20,0x70,0x72,0x6f,0x74,0x6f,0x63,0x6f,0x6c,0x0,0x41,0x64,0x64,0x72,0x65,0x73,0x73,0x20,0x6e,0x6f,0x74,0x20,0x61,0x76,0x61,0x69,0x6c,0x61,0x62,0x6c,0x65,0x0,0x4e,0x65,0x74,0x77,0x6f,0x72,0x6b,0x20,0x69,0x73,0x20,0x64,0x6f,0x77,0x6e,0x0,0x4e,0x65,0x74,0x77,0x6f,0x72,0x6b,0x20,0x75,0x6e,0x72,0x65,0x61,0x63,0x68,0x61,0x62,0x6c,0x65,0x0,0x43,0x6f,0x6e,0x6e,0x65,0x63,0x74,0x69,0x6f,0x6e,0x20,0x72,0x65,0x73,0x65,0x74,0x20,0x62,0x79,0x20,0x6e,0x65,0x74,0x77,0x6f,0x72,0x6b,0x0,0x43,0x6f,0x6e,0x6e,0x65,0x63,0x74,0x69,0x6f,0x6e,0x20,0x61,0x62,0x6f,0x72,0x74,0x65,0x64,0x0,0x4e,0x6f,0x20,0x62,0x75,0x66,0x66,0x65,0x72,0x20,0x73,0x70,0x61,0x63,0x65,0x20,0x61,0x76,0x61,0x69,0x6c,0x61,0x62,0x6c,0x65,0x0,0x53,0x6f,0x63,0x6b,0x65,0x74,0x20,0x69,0x73,0x20,0x63,0x6f,0x6e,0x6e,0x65,0x63,0x74,0x65,0x64,0x0,0x53,0x6f,0x63,0x6b,0x65,0x74,0x20,0x6e,0x6f,0x74,0x20,0x63,0x6f,0x6e,0x6e,0x65,0x63,0x74,0x65,0x64,0x0,0x4f,0x70,0x65,0x72,0x61,0x74,0x69,0x6f,0x6e,0x20,0x61,0x6c,0x72,0x65,0x61,0x64,0x79,0x20,0x69,0x6e,0x20,0x70,0x72,0x6f,0x67,0x72,0x65,0x73,0x73,0x0,0x4f,0x70,0x65,0x72,0x61,0x74,0x69,0x6f,0x6e,0x20,0x69,0x6e,0x20,0x70,0x72,0x6f,0x67,0x72,0x65,0x73,0x73,0x0,0x53,0x74,0x61,0x6c,0x65,0x20,0x66,0x69,0x6c,0x65,0x20,0x68,0x61,0x6e,0x64,0x6c,0x65,0x0,0x51,0x75,0x6f,0x74,0x61,0x20,0x65,0x78,0x63,0x65,0x65,0x64,0x65,0x64,0x0,0x4d,0x75,0x6c,0x74,0x69,0x68,0x6f,0x70,0x20,0x61,0x74,0x74,0x65,0x6d,0x70,0x74,0x65,0x64,0x0,0x43,0x61,0x70,0x61,0x62,0x69,0x6c,0x69,0x74,0x69,0x65,0x73,0x20,0x69,0x6e,0x73,0x75,0x66,0x66,0x69,0x63,0x69,0x65,0x6e,0x74,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x75,0x2,0x4e,0x0,0xd6,0x1,0xe2,0x4,0xb9,0x4,0x18,0x1,0x8e,0x5,0xed,0x2,0x16,0x4,0xf2,0x0,0x97,0x3,0x1,0x3,0x38,0x5,0xaf,0x1,0x82,0x1,0x4f,0x3,0x2f,0x4,0x1e,0x0,0xd4,0x5,0xa2,0x0,0x12,0x3,0x1e,0x3,0xc2,0x1,0xde,0x3,0x8,0x0,0xac,0x5,0x0,0x1,0x64,0x2,0xf1,0x1,0x65,0x5,0x34,0x2,0x8c,0x2,0xcf,0x2,0x2d,0x3,0x4c,0x4,0xe3,0x5,0x9f,0x2,0xf8,0x4,0x1c,0x5,0x8,0x5,0xb1,0x2,0x4b,0x5,0x15,0x2,0x78,0x0,0x52,0x2,0x3c,0x3,0xf1,0x3,0xe4,0x0,0xc3,0x3,0x7d,0x4,0xcc,0x0,0xaa,0x3,0x79,0x5,0x24,0x2,0x6e,0x1,0x6d,0x3,0x22,0x4,0xab,0x4,0x44,0x0,0xfb,0x1,0xae,0x0,0x83,0x3,0x60,0x0,0xe5,0x1,0x7,0x4,0x94,0x4,0x5e,0x4,0x2b,0x0,0x58,0x1,0x39,0x1,0x92,0x0,0xc2,0x5,0x9b,0x1,0x43,0x2,0x46,0x1,0xf6,0x5,0x0,0x0,0x0,0x0,0x0,0x0,0x19,0x0,0xa,0x0,0x19,0x19,0x19,0x0,0x0,0x0,0x0,0x5,0x0,0x0,0x0,0x0,0x0,0x0,0x9,0x0,0x0,0x0,0x0,0xb,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x19,0x0,0x11,0xa,0x19,0x19,0x19,0x3,0xa,0x7,0x0,0x1,0x1b,0x9,0xb,0x18,0x0,0x0,0x9,0x6,0xb,0x0,0x0,0xb,0x0,0x6,0x19,0x0,0x0,0x0,0x19,0x19,0x19,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x19,0x0,0xa,0xd,0x19,0x19,0x19,0x0,0xd,0x0,0x0,0x2,0x0,0x9,0xe,0x0,0x0,0x0,0x9,0x0,0xe,0x0,0x0,0xe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x13,0x0,0x0,0x0,0x0,0x13,0x0,0x0,0x0,0x0,0x9,0xc,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x0,0xc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,0x0,0x0,0x0,0x4,0xf,0x0,0x0,0x0,0x0,0x9,0x10,0x0,0x0,0x0,0x0,0x0,0x10,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x12,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x11,0x0,0x0,0x0,0x0,0x11,0x0,0x0,0x0,0x0,0x9,0x12,0x0,0x0,0x0,0x0,0x0,0x12,0x0,0x0,0x12,0x0,0x0,0x1a,0x0,0x0,0x0,0x1a,0x1a,0x1a,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1a,0x0,0x0,0x0,0x1a,0x1a,0x1a,0x0,0x0,0x0,0x0,0x0,0x0,0x9,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x14,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x17,0x0,0x0,0x0,0x0,0x17,0x0,0x0,0x0,0x0,0x9,0x14,0x0,0x0,0x0,0x0,0x0,0x14,0x0,0x0,0x14,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x16,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x15,0x0,0x0,0x0,0x0,0x15,0x0,0x0,0x0,0x0,0x9,0x16,0x0,0x0,0x0,0x0,0x0,0x16,0x0,0x0,0x16,0x0,0x0,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x41,0x42,0x43,0x44,0x45,0x46,
};

const U8 d1[]={
0x5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0x0,0x0,0x0,0x4,0x0,0x0,0x0,0x88,0xe,0x0,0x0,0x0,0x4,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xa,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x80,0xd,0x0,0x0,0x0,0x0,0x0,0x0,0x5,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x4,0x0,0x0,0x0,0xb4,0x12,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf8,0xd,0x0,0x0,
};

U32 f35(exampleInstance*i,U32 l0,U32 l1,U32 l2,U32 l3) {
U32 l4=0;
U32 l5=0;
U32 l6=0;
U32 l7=0;
U32 l8=0;
U32 si0,si1,si2,si3;
si0=l2;
si1=l1;
si0*=si1;
l4=si0;
si0=l3;
si0=i32_load(i->m0,(U64)si0+16U);
l5=si0;
if(si0){
goto L2;
}
si0=0U;
l6=si0;
si0=l3;
si0=f33(i,si0);
if(si0){
goto L1;
}
si0=l3;
si0=i32_load(i->m0,(U64)si0+16U);
l5=si0;
L2:;
si0=l5;
si1=l3;
si1=i32_load(i->m0,(U64)si1+20U);
l7=si1;
si0-=si1;
si1=l4;
si0=si0 >= si1;
if(si0){
goto L3;
}
si0=l3;
si1=l0;
si2=l4;
si3=l3;
si3=i32_load(i->m0,(U64)si3+32U);
si0=TF(i->t0,si3,U32 (*)(exampleInstance*,U32,U32,U32))(i,si0,si1,si2);
l6=si0;
goto L1;
L3:;
si0=0U;
l8=si0;
si0=l4;
if(si0){
goto L5;
}
si0=l4;
l5=si0;
goto L4;
L5:;
si0=0U;
l5=si0;
si0=l3;
si0=i32_load(i->m0,(U64)si0+64U);
si1=0U;
si0=(U32)((I32)si0>=(I32)si1);
if(si0){
goto L6;
}
si0=l4;
l5=si0;
goto L4;
L6:;
si0=l0;
si1=l4;
si0+=si1;
l6=si0;
L8:;
{
si0=l6;
si1=l5;
si0+=si1;
si1=-1U;
si0+=si1;
si0=i32_load8_u(i->m0,(U64)si0);
si1=10U;
si0=si0 == si1;
if(si0){
goto L7;
}
si0=l4;
si1=l5;
si2=-1U;
si1+=si2;
l5=si1;
si0+=si1;
if(si0){
goto L8;
}
}
si0=0U;
l8=si0;
si0=l4;
l5=si0;
goto L4;
L7:;
si0=l3;
si1=l0;
si2=l4;
si3=l5;
si2+=si3;
l8=si2;
si3=l3;
si3=i32_load(i->m0,(U64)si3+32U);
si0=TF(i->t0,si3,U32 (*)(exampleInstance*,U32,U32,U32))(i,si0,si1,si2);
l6=si0;
si1=l8;
si0=si0 < si1;
if(si0){
goto L1;
}
si0=l8;
si1=l0;
si0+=si1;
l0=si0;
si0=0U;
si1=l5;
si0-=si1;
l5=si0;
si0=l3;
si0=i32_load(i->m0,(U64)si0+20U);
l7=si0;
L4:;
si0=l7;
si1=l0;
si2=l5;
si0=f49(i,si0,si1,si2);
si0=l3;
si1=l3;
si1=i32_load(i->m0,(U64)si1+20U);
si2=l5;
si1+=si2;
i32_store(i->m0,(U64)si0+20U,si1);
si0=l8;
si1=l5;
si0+=si1;
l6=si0;
L1:;
si0=l6;
si1=l4;
si0=si0 != si1;
if(si0){
goto L9;
}
si0=l2;
si1=0U;
si2=l1;
si0=si2?si0:si1;
goto L0;
L9:;
si0=l6;
si1=l1;
si0=DIV_U(si0,si1);
L0:;
return si0;
}

void f20(exampleInstance*i) {
f19(i);
f32(i);
L0:;
}

U32 f33(exampleInstance*i,U32 l0) {
U32 l1=0;
U32 si0,si1,si2;
U64 sj1;
si0=l0;
si1=l0;
si1=i32_load(i->m0,(U64)si1+60U);
l1=si1;
si2=-1U;
si1+=si2;
si2=l1;
si1|=si2;
i32_store(i->m0,(U64)si0+60U,si1);
si0=l0;
si0=i32_load(i->m0,(U64)si0);
l1=si0;
si1=8U;
si0&=si1;
si0=!(si0);
if(si0){
goto L1;
}
si0=l0;
si1=l1;
si2=32U;
si1|=si2;
i32_store(i->m0,(U64)si0,si1);
si0=-1U;
goto L0;
L1:;
si0=l0;
sj1=0ULL;
i64_store(i->m0,(U64)si0+4U,sj1);
si0=l0;
si1=l0;
si1=i32_load(i->m0,(U64)si1+40U);
l1=si1;
i32_store(i->m0,(U64)si0+24U,si1);
si0=l0;
si1=l1;
i32_store(i->m0,(U64)si0+20U,si1);
si0=l0;
si1=l1;
si2=l0;
si2=i32_load(i->m0,(U64)si2+44U);
si1+=si2;
i32_store(i->m0,(U64)si0+16U,si1);
si0=0U;
L0:;
return si0;
}

U32 f17(exampleInstance*i,U32 l0,U32 l1,U32 l2,U32 l3) {
U32 si0,si1,si2,si3;
si0=l0;
si1=l1;
si2=l2;
si3=l3;
si0=wasi_snapshot_preview1__fd_write(i,si0,si1,si2,si3);
si1=65535U;
si0&=si1;
L0:;
return si0;
}

U32 f31(exampleInstance*i) {
U32 si0;
si0=4744U;
L0:;
return si0;
}

void f12(exampleInstance*i) {
U32 l0=0;
U32 si0,si1;
si0=i->g1;
si1=3696U;
si0+=si1;
si0=i32_load(i->m0,(U64)si0);
if(si0){
goto L2;
}
si0=i->g1;
si1=3696U;
si0+=si1;
si1=1U;
i32_store(i->m0,(U64)si0,si1);
f11(i);
si0=f13(i);
l0=si0;
f20(i);
si0=l0;
if(si0){
goto L1;
}
goto L0;
L2:;
UNREACHABLE;
L1:;
si0=l0;
f18(i,si0);
UNREACHABLE;
L0:;
}

void f47(exampleInstance*i,U32 l0,U32 l1,U32 l2,U32 l3,U32 l4) {
U32 l5=0;
U32 si0,si1,si2,si3,si4,si5;
si0=i->g0;
si1=256U;
si0-=si1;
l5=si0;
i->g0=si0;
si0=l2;
si1=l3;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L1;
}
si0=l4;
si1=73728U;
si0&=si1;
if(si0){
goto L1;
}
si0=l5;
si1=l1;
si2=l2;
si3=l3;
si2-=si3;
l3=si2;
si3=256U;
si4=l3;
si5=256U;
si4=si4 < si5;
l4=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
l2=si0;
si0=l4;
if(si0){
goto L2;
}
L3:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L4;
}
si0=l2;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L4:;
si0=l3;
si1=-256U;
si0+=si1;
l3=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L3;
}
}
L2:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L1;
}
si0=l2;
si1=l3;
si2=l0;
si0=f34(i,si0,si1,si2);
L1:;
si0=l5;
si1=256U;
si0+=si1;
i->g0=si0;
L0:;
}

U32 f37(exampleInstance*i,U32 l0,U32 l1) {
U32 si0,si1;
si0=l0;
si1=l1;
si0=f36(i,si0,si1);
L0:;
return si0;
}

U32 f53(exampleInstance*i,U32 l0,U32 l1) {
U32 l2=0;
U32 si0,si1,si2;
si0=l0;
si1=0U;
si2=l1;
si0=f52(i,si0,si1,si2);
l2=si0;
si1=l0;
si0-=si1;
si1=l1;
si2=l2;
si0=si2?si0:si1;
L0:;
return si0;
}

U64 f30(exampleInstance*i,U32 l0,U64 l1,U32 l2) {
U32 si0,si2;
U64 sj0,sj1;
si0=l0;
si0=i32_load(i->m0,(U64)si0+56U);
sj1=l1;
si2=l2;
sj0=f29(i,si0,sj1,si2);
L0:;
return sj0;
}

U32 f13(exampleInstance*i) {
U32 l0=0;
U32 l1=0;
U32 l2=0;
U32 l3=0;
U32 l4=0;
U32 l5=0;
U32 l6=0;
U32 l7=0;
U32 l8=0;
U32 l9=0;
U32 l10=0;
U32 l11=0;
U32 l12=0;
U32 l13=0;
U32 l14=0;
U32 l15=0;
U32 l16=0;
U32 l17=0;
U32 l18=0;
U32 l19=0;
U32 l20=0;
U32 l21=0;
U32 si0,si1;
si0=i->g0;
l0=si0;
si0=16U;
l1=si0;
si0=l0;
si1=l1;
si0-=si1;
l2=si0;
si0=l2;
i->g0=si0;
si0=1057U;
l3=si0;
si0=l3;
si0=env__w2c2BridgeMemoryOffset(i,si0);
l4=si0;
si0=l4;
si0=env__objc_getClass(i,si0);
l5=si0;
si0=l2;
si1=l5;
i32_store(i->m0,(U64)si0+12U,si1);
si0=l2;
si0=i32_load(i->m0,(U64)si0+12U);
l6=si0;
si0=l6;
si0=env___CM_String_alloc(i,si0);
l7=si0;
si0=1085U;
l8=si0;
si0=l8;
si0=env__w2c2BridgeMemoryOffset(i,si0);
l9=si0;
si0=l7;
si1=l9;
si0=env___IM_String_initWithCString_C(i,si0,si1);
l10=si0;
si0=l2;
si1=l10;
i32_store(i->m0,(U64)si0+8U,si1);
si0=l2;
si0=i32_load(i->m0,(U64)si0+8U);
l11=si0;
si0=l11;
env___IM_String_log(i,si0);
si0=l2;
si0=i32_load(i->m0,(U64)si0+8U);
l12=si0;
si0=l2;
si0=i32_load(i->m0,(U64)si0+8U);
l13=si0;
si0=l12;
si1=l13;
si0=env___IM_String_isEqualToString_C(i,si0,si1);
l14=si0;
si0=24U;
l15=si0;
si0=l14;
si1=l15;
si0<<=(si1&31);
l16=si0;
si0=l16;
si1=l15;
si0=(U32)((I32)si0>>(si1&31));
l17=si0;
si0=l2;
si1=l17;
i32_store(i->m0,(U64)si0,si1);
si0=1099U;
l18=si0;
si0=l18;
si1=l2;
si0=f21(i,si0,si1);
si0=0U;
l19=si0;
si0=16U;
l20=si0;
si0=l2;
si1=l20;
si0+=si1;
l21=si0;
si0=l21;
i->g0=si0;
si0=l19;
goto L0;
L0:;
return si0;
}

U32 f45(exampleInstance*i,U32 l0,U32 l1,U32 l2,U32 l3,U32 l4) {
U32 l5=0;
U32 l6=0;
U32 l7=0;
U32 l8=0;
U32 l9=0;
U32 l10=0;
U32 l11=0;
U32 l12=0;
U32 l13=0;
U32 l14=0;
U32 l15=0;
U32 l16=0;
U32 l17=0;
U32 l18=0;
U32 l19=0;
U32 l20=0;
U32 l21=0;
U32 l22=0;
U32 l23=0;
U32 l24=0;
U32 l25=0;
U32 l26=0;
U32 l27=0;
U32 l28=0;
U32 l29=0;
U32 l30=0;
U32 l31=0;
U64 l32=0;
U64 l33=0;
F64 l34=0;
U32 l35=0;
U32 l36=0;
U32 l37=0;
U32 l38=0;
U32 l39=0;
U32 l40=0;
U32 l41=0;
U32 l42=0;
U32 l43=0;
F64 l44=0;
U32 si0,si1,si2,si3,si4,si5;
U64 sj0,sj1,sj2,sj3;
F64 sd0,sd1,sd2,sd3;
si0=i->g0;
si1=880U;
si0-=si1;
l5=si0;
i->g0=si0;
si0=l3;
si1=-384U;
si0+=si1;
l6=si0;
si0=l5;
si1=68U;
si0+=si1;
si1=12U;
si0+=si1;
l7=si0;
si0=0U;
si1=l5;
si2=112U;
si1+=si2;
si0-=si1;
l8=si0;
si0=l5;
si1=112U;
si0+=si1;
si1=-4100U;
si0+=si1;
l9=si0;
si0=l5;
si1=55U;
si0+=si1;
l10=si0;
si0=l5;
si1=68U;
si0+=si1;
si1=11U;
si0+=si1;
l11=si0;
si0=l5;
si1=80U;
si0+=si1;
si1=-1U;
si0+=si1;
l12=si0;
si0=l5;
si1=80U;
si0+=si1;
si1=8U;
si0|=si1;
l13=si0;
si0=l5;
si1=80U;
si0+=si1;
si1=9U;
si0|=si1;
l14=si0;
si0=l5;
si1=68U;
si0+=si1;
si1=10U;
si0+=si1;
l15=si0;
si0=l5;
si1=56U;
si0+=si1;
l16=si0;
si0=0U;
l17=si0;
si0=0U;
l18=si0;
si0=0U;
l19=si0;
L4:;
{
si0=l1;
l20=si0;
si0=l19;
si1=l18;
si2=2147483647U;
si1^=si2;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L3;
}
si0=l19;
si1=l18;
si0+=si1;
l18=si0;
si0=l20;
si0=i32_load8_u(i->m0,(U64)si0);
l19=si0;
si0=!(si0);
if(si0){
goto L13;
}
si0=l20;
l1=si0;
L14:;
{
si0=l19;
si1=255U;
si0&=si1;
l19=si0;
si0=!(si0);
if(si0){
goto L17;
}
si0=l19;
si1=37U;
si0=si0 != si1;
if(si0){
goto L15;
}
si0=l1;
l21=si0;
si0=l1;
l19=si0;
L18:;
{
si0=l19;
si0=i32_load8_u(i->m0,(U64)si0+1U);
si1=37U;
si0=si0 == si1;
if(si0){
goto L19;
}
si0=l19;
l1=si0;
goto L16;
L19:;
si0=l21;
si1=1U;
si0+=si1;
l21=si0;
si0=l19;
si0=i32_load8_u(i->m0,(U64)si0+2U);
l22=si0;
si0=l19;
si1=2U;
si0+=si1;
l1=si0;
l19=si0;
si0=l22;
si1=37U;
si0=si0 == si1;
if(si0){
goto L18;
}
goto L16;
}
L17:;
si0=l1;
l21=si0;
L16:;
si0=l21;
si1=l20;
si0-=si1;
l19=si0;
si1=l18;
si2=2147483647U;
si1^=si2;
l21=si1;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L3;
}
si0=l0;
si0=!(si0);
if(si0){
goto L20;
}
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L20;
}
si0=l20;
si1=l19;
si2=l0;
si0=f34(i,si0,si1,si2);
L20:;
si0=l19;
if(si0){
goto L4;
}
si0=l1;
si1=1U;
si0+=si1;
l19=si0;
si0=-1U;
l23=si0;
si0=l1;
si0=i32_load8_s(i->m0,(U64)si0+1U);
l24=si0;
si1=-48U;
si0+=si1;
l22=si0;
si1=9U;
si0=si0 > si1;
if(si0){
goto L21;
}
si0=l1;
si0=i32_load8_u(i->m0,(U64)si0+2U);
si1=36U;
si0=si0 != si1;
if(si0){
goto L21;
}
si0=l1;
si1=3U;
si0+=si1;
l19=si0;
si0=l1;
si0=i32_load8_s(i->m0,(U64)si0+3U);
l24=si0;
si0=1U;
l17=si0;
si0=l22;
l23=si0;
L21:;
si0=0U;
l25=si0;
si0=l24;
si1=-32U;
si0+=si1;
l1=si0;
si1=31U;
si0=si0 > si1;
if(si0){
goto L22;
}
si0=1U;
si1=l1;
si0<<=(si1&31);
l1=si0;
si1=75913U;
si0&=si1;
si0=!(si0);
if(si0){
goto L22;
}
si0=l19;
si1=1U;
si0+=si1;
l22=si0;
si0=0U;
l25=si0;
L23:;
{
si0=l1;
si1=l25;
si0|=si1;
l25=si0;
si0=l22;
l19=si0;
si0=i32_load8_s(i->m0,(U64)si0);
l24=si0;
si1=-32U;
si0+=si1;
l1=si0;
si1=32U;
si0=si0 >= si1;
if(si0){
goto L22;
}
si0=l19;
si1=1U;
si0+=si1;
l22=si0;
si0=1U;
si1=l1;
si0<<=(si1&31);
l1=si0;
si1=75913U;
si0&=si1;
if(si0){
goto L23;
}
}
L22:;
si0=l24;
si1=42U;
si0=si0 != si1;
if(si0){
goto L24;
}
si0=l19;
si0=i32_load8_s(i->m0,(U64)si0+1U);
si1=-48U;
si0+=si1;
l1=si0;
si1=9U;
si0=si0 > si1;
if(si0){
goto L26;
}
si0=l19;
si0=i32_load8_u(i->m0,(U64)si0+2U);
si1=36U;
si0=si0 != si1;
if(si0){
goto L26;
}
si0=l4;
si1=l1;
si2=2U;
si1<<=(si2&31);
si0+=si1;
si1=10U;
i32_store(i->m0,(U64)si0,si1);
si0=l19;
si1=3U;
si0+=si1;
l22=si0;
si0=l6;
si1=l19;
si1=i32_load8_s(i->m0,(U64)si1+1U);
si2=3U;
si1<<=(si2&31);
si0+=si1;
si0=i32_load(i->m0,(U64)si0);
l26=si0;
si0=1U;
l17=si0;
goto L25;
L26:;
si0=l17;
if(si0){
goto L11;
}
si0=l19;
si1=1U;
si0+=si1;
l22=si0;
si0=l0;
if(si0){
goto L27;
}
si0=0U;
l17=si0;
si0=0U;
l26=si0;
goto L12;
L27:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l1;
si0=i32_load(i->m0,(U64)si0);
l26=si0;
si0=0U;
l17=si0;
L25:;
si0=l26;
si1=-1U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L12;
}
si0=0U;
si1=l26;
si0-=si1;
l26=si0;
si0=l25;
si1=8192U;
si0|=si1;
l25=si0;
goto L12;
L24:;
si0=0U;
l26=si0;
si0=l24;
si1=-48U;
si0+=si1;
l1=si0;
si1=9U;
si0=si0 <= si1;
if(si0){
goto L28;
}
si0=l19;
l22=si0;
goto L12;
L28:;
si0=0U;
l26=si0;
L29:;
{
si0=l26;
si1=214748364U;
si0=si0 > si1;
if(si0){
goto L30;
}
si0=-1U;
si1=l26;
si2=10U;
si1*=si2;
l22=si1;
si2=l1;
si1+=si2;
si2=l1;
si3=l22;
si4=2147483647U;
si3^=si4;
si2=si2 > si3;
l24=si2;
si0=si2?si0:si1;
l26=si0;
si0=l19;
si0=i32_load8_s(i->m0,(U64)si0+1U);
l1=si0;
si0=l19;
si1=1U;
si0+=si1;
l22=si0;
l19=si0;
si0=l1;
si1=-48U;
si0+=si1;
l1=si0;
si1=10U;
si0=si0 < si1;
if(si0){
goto L29;
}
si0=l24;
if(si0){
goto L3;
}
goto L12;
L30:;
si0=l19;
si0=i32_load8_s(i->m0,(U64)si0+1U);
l1=si0;
si0=-1U;
l26=si0;
si0=l19;
si1=1U;
si0+=si1;
l19=si0;
si0=l1;
si1=-48U;
si0+=si1;
l1=si0;
si1=10U;
si0=si0 < si1;
if(si0){
goto L29;
}
goto L3;
}
L15:;
si0=l1;
si0=i32_load8_u(i->m0,(U64)si0+1U);
l19=si0;
si0=l1;
si1=1U;
si0+=si1;
l1=si0;
goto L14;
}
L13:;
si0=l0;
if(si0){
goto L1;
}
si0=l17;
if(si0){
goto L31;
}
si0=0U;
l18=si0;
goto L1;
L31:;
si0=l4;
si0=i32_load(i->m0,(U64)si0+4U);
l1=si0;
if(si0){
goto L34;
}
si0=1U;
l1=si0;
goto L33;
L34:;
si0=l3;
si1=8U;
si0+=si1;
si1=l1;
si2=l2;
f46(i,si0,si1,si2);
si0=l4;
si0=i32_load(i->m0,(U64)si0+8U);
l1=si0;
if(si0){
goto L35;
}
si0=2U;
l1=si0;
goto L33;
L35:;
si0=l3;
si1=16U;
si0+=si1;
si1=l1;
si2=l2;
f46(i,si0,si1,si2);
si0=l4;
si0=i32_load(i->m0,(U64)si0+12U);
l1=si0;
if(si0){
goto L36;
}
si0=3U;
l1=si0;
goto L33;
L36:;
si0=l3;
si1=24U;
si0+=si1;
si1=l1;
si2=l2;
f46(i,si0,si1,si2);
si0=l4;
si0=i32_load(i->m0,(U64)si0+16U);
l1=si0;
if(si0){
goto L37;
}
si0=4U;
l1=si0;
goto L33;
L37:;
si0=l3;
si1=32U;
si0+=si1;
si1=l1;
si2=l2;
f46(i,si0,si1,si2);
si0=l4;
si0=i32_load(i->m0,(U64)si0+20U);
l1=si0;
if(si0){
goto L38;
}
si0=5U;
l1=si0;
goto L33;
L38:;
si0=l3;
si1=40U;
si0+=si1;
si1=l1;
si2=l2;
f46(i,si0,si1,si2);
si0=l4;
si0=i32_load(i->m0,(U64)si0+24U);
l1=si0;
if(si0){
goto L39;
}
si0=6U;
l1=si0;
goto L33;
L39:;
si0=l3;
si1=48U;
si0+=si1;
si1=l1;
si2=l2;
f46(i,si0,si1,si2);
si0=l4;
si0=i32_load(i->m0,(U64)si0+28U);
l1=si0;
if(si0){
goto L40;
}
si0=7U;
l1=si0;
goto L33;
L40:;
si0=l3;
si1=56U;
si0+=si1;
si1=l1;
si2=l2;
f46(i,si0,si1,si2);
si0=l4;
si0=i32_load(i->m0,(U64)si0+32U);
l1=si0;
if(si0){
goto L41;
}
si0=8U;
l1=si0;
goto L33;
L41:;
si0=l3;
si1=64U;
si0+=si1;
si1=l1;
si2=l2;
f46(i,si0,si1,si2);
si0=l4;
si0=i32_load(i->m0,(U64)si0+36U);
l1=si0;
if(si0){
goto L32;
}
si0=9U;
l1=si0;
L33:;
si0=l1;
si1=2U;
si0<<=(si1&31);
l1=si0;
L42:;
{
si0=l4;
si1=l1;
si0+=si1;
si0=i32_load(i->m0,(U64)si0);
if(si0){
goto L11;
}
si0=l1;
si1=4U;
si0+=si1;
l1=si0;
si1=40U;
si0=si0 != si1;
if(si0){
goto L42;
}
}
si0=1U;
l18=si0;
goto L1;
L32:;
si0=l3;
si1=72U;
si0+=si1;
si1=l1;
si2=l2;
f46(i,si0,si1,si2);
si0=1U;
l18=si0;
goto L1;
L12:;
si0=0U;
l19=si0;
si0=-1U;
l24=si0;
si0=l22;
si0=i32_load8_u(i->m0,(U64)si0);
si1=46U;
si0=si0 == si1;
if(si0){
goto L44;
}
si0=l22;
l1=si0;
si0=0U;
l27=si0;
goto L43;
L44:;
si0=l22;
si0=i32_load8_s(i->m0,(U64)si0+1U);
l24=si0;
si1=42U;
si0=si0 != si1;
if(si0){
goto L45;
}
si0=l22;
si0=i32_load8_s(i->m0,(U64)si0+2U);
si1=-48U;
si0+=si1;
l1=si0;
si1=9U;
si0=si0 > si1;
if(si0){
goto L46;
}
si0=l22;
si0=i32_load8_u(i->m0,(U64)si0+3U);
si1=36U;
si0=si0 != si1;
if(si0){
goto L46;
}
si0=l4;
si1=l1;
si2=2U;
si1<<=(si2&31);
si0+=si1;
si1=10U;
i32_store(i->m0,(U64)si0,si1);
si0=l22;
si1=4U;
si0+=si1;
l1=si0;
si0=l6;
si1=l22;
si1=i32_load8_s(i->m0,(U64)si1+2U);
si2=3U;
si1<<=(si2&31);
si0+=si1;
si0=i32_load(i->m0,(U64)si0);
l24=si0;
si1=-1U;
si0=(U32)((I32)si0>(I32)si1);
l27=si0;
goto L43;
L46:;
si0=l17;
if(si0){
goto L11;
}
si0=l22;
si1=2U;
si0+=si1;
l1=si0;
si0=l0;
if(si0){
goto L47;
}
si0=0U;
l24=si0;
si0=0U;
si1=-1U;
si0=(U32)((I32)si0>(I32)si1);
l27=si0;
goto L43;
L47:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l22=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l22;
si0=i32_load(i->m0,(U64)si0);
l24=si0;
si1=-1U;
si0=(U32)((I32)si0>(I32)si1);
l27=si0;
goto L43;
L45:;
si0=l22;
si1=1U;
si0+=si1;
l1=si0;
si0=l24;
si1=-48U;
si0+=si1;
l28=si0;
si1=9U;
si0=si0 <= si1;
if(si0){
goto L48;
}
si0=1U;
l27=si0;
si0=0U;
l24=si0;
goto L43;
L48:;
si0=0U;
l29=si0;
si0=l1;
l22=si0;
L49:;
{
si0=-1U;
l24=si0;
si0=l29;
si1=214748364U;
si0=si0 > si1;
if(si0){
goto L50;
}
si0=-1U;
si1=l29;
si2=10U;
si1*=si2;
l1=si1;
si2=l28;
si1+=si2;
si2=l28;
si3=l1;
si4=2147483647U;
si3^=si4;
si2=si2 > si3;
si0=si2?si0:si1;
l24=si0;
L50:;
si0=1U;
l27=si0;
si0=l22;
si0=i32_load8_s(i->m0,(U64)si0+1U);
l28=si0;
si0=l24;
l29=si0;
si0=l22;
si1=1U;
si0+=si1;
l1=si0;
l22=si0;
si0=l28;
si1=-48U;
si0+=si1;
l28=si0;
si1=10U;
si0=si0 < si1;
if(si0){
goto L49;
}
}
L43:;
L51:;
{
si0=l19;
l22=si0;
si0=l1;
si0=i32_load8_s(i->m0,(U64)si0);
l19=si0;
si1=-123U;
si0+=si1;
si1=-58U;
si0=si0 < si1;
if(si0){
goto L11;
}
si0=l1;
si1=1U;
si0+=si1;
l1=si0;
si0=l19;
si1=l22;
si2=58U;
si1*=si2;
si0+=si1;
si1=2911U;
si0+=si1;
si0=i32_load8_u(i->m0,(U64)si0);
l19=si0;
si1=-1U;
si0+=si1;
si1=8U;
si0=si0 < si1;
if(si0){
goto L51;
}
}
si0=l19;
si1=27U;
si0=si0 == si1;
if(si0){
goto L54;
}
si0=l19;
si0=!(si0);
if(si0){
goto L11;
}
si0=l23;
si1=0U;
si0=(U32)((I32)si0<(I32)si1);
if(si0){
goto L55;
}
si0=l4;
si1=l23;
si2=2U;
si1<<=(si2&31);
si0+=si1;
si1=l19;
i32_store(i->m0,(U64)si0,si1);
si0=l5;
si1=l3;
si2=l23;
si3=3U;
si2<<=(si3&31);
si1+=si2;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0+56U,sj1);
goto L53;
L55:;
si0=l0;
if(si0){
goto L56;
}
si0=0U;
l18=si0;
goto L1;
L56:;
si0=l5;
si1=56U;
si0+=si1;
si1=l19;
si2=l2;
f46(i,si0,si1,si2);
goto L52;
L54:;
si0=l23;
si1=-1U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L11;
}
L53:;
si0=0U;
l19=si0;
si0=l0;
si0=!(si0);
if(si0){
goto L4;
}
L52:;
si0=l25;
si1=-65537U;
si0&=si1;
l29=si0;
si1=l25;
si2=l25;
si3=8192U;
si2&=si3;
si0=si2?si0:si1;
l30=si0;
si0=l1;
si1=-1U;
si0+=si1;
si0=i32_load8_s(i->m0,(U64)si0);
l19=si0;
si1=-45U;
si0&=si1;
si1=l19;
si2=l19;
si3=15U;
si2&=si3;
si3=3U;
si2=si2 == si3;
si0=si2?si0:si1;
si1=l19;
si2=l22;
si0=si2?si0:si1;
l31=si0;
si1=-65U;
si0+=si1;
switch(si0){
case 0:
goto L57;
case 1:
goto L10;
case 2:
goto L60;
case 3:
goto L10;
case 4:
goto L57;
case 5:
goto L57;
case 6:
goto L57;
case 7:
goto L10;
case 8:
goto L10;
case 9:
goto L10;
case 10:
goto L10;
case 11:
goto L10;
case 12:
goto L10;
case 13:
goto L10;
case 14:
goto L10;
case 15:
goto L10;
case 16:
goto L10;
case 17:
goto L10;
case 18:
goto L61;
case 19:
goto L10;
case 20:
goto L10;
case 21:
goto L10;
case 22:
goto L10;
case 23:
goto L70;
case 24:
goto L10;
case 25:
goto L10;
case 26:
goto L10;
case 27:
goto L10;
case 28:
goto L10;
case 29:
goto L10;
case 30:
goto L10;
case 31:
goto L10;
case 32:
goto L57;
case 33:
goto L10;
case 34:
goto L65;
case 35:
goto L68;
case 36:
goto L57;
case 37:
goto L57;
case 38:
goto L57;
case 39:
goto L10;
case 40:
goto L68;
case 41:
goto L10;
case 42:
goto L10;
case 43:
goto L10;
case 44:
goto L64;
case 45:
goto L72;
case 46:
goto L69;
case 47:
goto L71;
case 48:
goto L10;
case 49:
goto L10;
case 50:
goto L63;
case 51:
goto L10;
case 52:
goto L73;
case 53:
goto L10;
case 54:
goto L10;
case 55:
goto L70;
default:
goto L10;
}
L73:;
si0=0U;
l28=si0;
si0=1024U;
l23=si0;
si0=l5;
sj0=i64_load(i->m0,(U64)si0+56U);
l32=sj0;
goto L67;
L72:;
si0=0U;
l19=si0;
si0=l22;
si1=255U;
si0&=si1;
switch(si0){
case 0:
goto L80;
case 1:
goto L79;
case 2:
goto L78;
case 3:
goto L77;
case 4:
goto L76;
case 5:
goto L4;
case 6:
goto L75;
case 7:
goto L74;
default:
goto L4;
}
L80:;
si0=l5;
si0=i32_load(i->m0,(U64)si0+56U);
si1=l18;
i32_store(i->m0,(U64)si0,si1);
goto L4;
L79:;
si0=l5;
si0=i32_load(i->m0,(U64)si0+56U);
si1=l18;
i32_store(i->m0,(U64)si0,si1);
goto L4;
L78:;
si0=l5;
si0=i32_load(i->m0,(U64)si0+56U);
si1=l18;
sj1=(U64)(I64)(I32)(si1);
i64_store(i->m0,(U64)si0,sj1);
goto L4;
L77:;
si0=l5;
si0=i32_load(i->m0,(U64)si0+56U);
si1=l18;
i32_store16(i->m0,(U64)si0,si1);
goto L4;
L76:;
si0=l5;
si0=i32_load(i->m0,(U64)si0+56U);
si1=l18;
i32_store8(i->m0,(U64)si0,si1);
goto L4;
L75:;
si0=l5;
si0=i32_load(i->m0,(U64)si0+56U);
si1=l18;
i32_store(i->m0,(U64)si0,si1);
goto L4;
L74:;
si0=l5;
si0=i32_load(i->m0,(U64)si0+56U);
si1=l18;
sj1=(U64)(I64)(I32)(si1);
i64_store(i->m0,(U64)si0,sj1);
goto L4;
L71:;
si0=l24;
si1=8U;
si2=l24;
si3=8U;
si2=si2 > si3;
si0=si2?si0:si1;
l24=si0;
si0=l30;
si1=8U;
si0|=si1;
l30=si0;
si0=120U;
l31=si0;
L70:;
si0=0U;
l28=si0;
si0=1024U;
l23=si0;
si0=l5;
sj0=i64_load(i->m0,(U64)si0+56U);
l32=sj0;
si0=!(sj0);
si0=!(si0);
if(si0){
goto L81;
}
si0=l16;
l20=si0;
goto L66;
L81:;
si0=l31;
si1=32U;
si0&=si1;
l22=si0;
si0=l16;
l20=si0;
L82:;
{
si0=l20;
si1=-1U;
si0+=si1;
l20=si0;
sj1=l32;
si1=(U32)(sj1);
si2=15U;
si1&=si2;
si2=3440U;
si1+=si2;
si1=i32_load8_u(i->m0,(U64)si1);
si2=l22;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
sj0=l32;
sj1=15ULL;
si0=sj0 > sj1;
l19=si0;
sj0=l32;
sj1=4ULL;
sj0>>=(sj1&63);
l32=sj0;
si0=l19;
if(si0){
goto L82;
}
}
si0=l30;
si1=8U;
si0&=si1;
si0=!(si0);
if(si0){
goto L66;
}
si0=l31;
si1=4U;
si0=(U32)((I32)si0>>(si1&31));
si1=1024U;
si0+=si1;
l23=si0;
si0=2U;
l28=si0;
goto L66;
L69:;
si0=l16;
l20=si0;
si0=l5;
sj0=i64_load(i->m0,(U64)si0+56U);
l32=sj0;
si0=!(sj0);
if(si0){
goto L83;
}
si0=l16;
l20=si0;
L84:;
{
si0=l20;
si1=-1U;
si0+=si1;
l20=si0;
sj1=l32;
si1=(U32)(sj1);
si2=7U;
si1&=si2;
si2=48U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
sj0=l32;
sj1=7ULL;
si0=sj0 > sj1;
l19=si0;
sj0=l32;
sj1=3ULL;
sj0>>=(sj1&63);
l32=sj0;
si0=l19;
if(si0){
goto L84;
}
}
L83:;
si0=0U;
l28=si0;
si0=1024U;
l23=si0;
si0=l30;
si1=8U;
si0&=si1;
si0=!(si0);
if(si0){
goto L66;
}
si0=l24;
si1=l16;
si2=l20;
si1-=si2;
l19=si1;
si2=1U;
si1+=si2;
si2=l24;
si3=l19;
si2=(U32)((I32)si2>(I32)si3);
si0=si2?si0:si1;
l24=si0;
goto L66;
L68:;
si0=l5;
sj0=i64_load(i->m0,(U64)si0+56U);
l32=sj0;
sj1=-1ULL;
si0=(U64)((I64)sj0>(I64)sj1);
if(si0){
goto L85;
}
si0=l5;
sj1=0ULL;
sj2=l32;
sj1-=sj2;
l32=sj1;
i64_store(i->m0,(U64)si0+56U,sj1);
si0=1U;
l28=si0;
si0=1024U;
l23=si0;
goto L67;
L85:;
si0=l30;
si1=2048U;
si0&=si1;
si0=!(si0);
if(si0){
goto L86;
}
si0=1U;
l28=si0;
si0=1025U;
l23=si0;
goto L67;
L86:;
si0=1026U;
si1=1024U;
si2=l30;
si3=1U;
si2&=si3;
l28=si2;
si0=si2?si0:si1;
l23=si0;
L67:;
sj0=l32;
sj1=4294967296ULL;
si0=sj0 >= sj1;
if(si0){
goto L88;
}
sj0=l32;
l33=sj0;
si0=l16;
l20=si0;
goto L87;
L88:;
si0=l16;
l20=si0;
L89:;
{
si0=l20;
si1=-1U;
si0+=si1;
l20=si0;
sj1=l32;
sj2=l32;
sj3=10ULL;
sj2=DIV_U(sj2,sj3);
l33=sj2;
sj3=10ULL;
sj2*=sj3;
sj1-=sj2;
si1=(U32)(sj1);
si2=48U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
sj0=l32;
sj1=42949672959ULL;
si0=sj0 > sj1;
l19=si0;
sj0=l33;
l32=sj0;
si0=l19;
if(si0){
goto L89;
}
}
L87:;
sj0=l33;
si0=(U32)(sj0);
l19=si0;
si0=!(si0);
if(si0){
goto L66;
}
L90:;
{
si0=l20;
si1=-1U;
si0+=si1;
l20=si0;
si1=l19;
si2=l19;
si3=10U;
si2=DIV_U(si2,si3);
l22=si2;
si3=10U;
si2*=si3;
si1-=si2;
si2=48U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l19;
si1=9U;
si0=si0 > si1;
l25=si0;
si0=l22;
l19=si0;
si0=l25;
if(si0){
goto L90;
}
}
L66:;
si0=l27;
si1=l24;
si2=0U;
si1=(U32)((I32)si1<(I32)si2);
si0&=si1;
if(si0){
goto L3;
}
si0=l30;
si1=-65537U;
si0&=si1;
si1=l30;
si2=l27;
si0=si2?si0:si1;
l29=si0;
si0=l5;
sj0=i64_load(i->m0,(U64)si0+56U);
l32=sj0;
sj1=0ULL;
si0=sj0 != sj1;
if(si0){
goto L91;
}
si0=0U;
l25=si0;
si0=l24;
if(si0){
goto L91;
}
si0=l16;
l20=si0;
si0=l16;
l19=si0;
goto L9;
L91:;
si0=l24;
si1=l16;
si2=l20;
si1-=si2;
sj2=l32;
si2=!(sj2);
si1+=si2;
l19=si1;
si2=l24;
si3=l19;
si2=(U32)((I32)si2>(I32)si3);
si0=si2?si0:si1;
l25=si0;
si0=l16;
l19=si0;
goto L9;
L65:;
si0=l5;
si1=l5;
sj1=i64_load(i->m0,(U64)si1+56U);
i64_store8(i->m0,(U64)si0+55U,sj1);
si0=0U;
l28=si0;
si0=1024U;
l23=si0;
si0=1U;
l25=si0;
si0=l10;
l20=si0;
si0=l16;
l19=si0;
goto L9;
L64:;
si0=3700U;
si0=i32_load(i->m0,(U64)si0);
si0=f38(i,si0);
l20=si0;
goto L62;
L63:;
si0=l5;
si0=i32_load(i->m0,(U64)si0+56U);
l19=si0;
si1=1078U;
si2=l19;
si0=si2?si0:si1;
l20=si0;
L62:;
si0=l20;
si1=l20;
si2=l24;
si3=2147483647U;
si4=l24;
si5=2147483647U;
si4=si4 < si5;
si2=si4?si2:si3;
si1=f53(i,si1,si2);
l25=si1;
si0+=si1;
l19=si0;
si0=0U;
l28=si0;
si0=1024U;
l23=si0;
si0=l24;
si1=-1U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L9;
}
si0=l19;
si0=i32_load8_u(i->m0,(U64)si0);
si0=!(si0);
if(si0){
goto L9;
}
goto L3;
L61:;
si0=l5;
si0=i32_load(i->m0,(U64)si0+56U);
l20=si0;
si0=l24;
if(si0){
goto L59;
}
si0=0U;
l19=si0;
goto L58;
L60:;
si0=l5;
si1=0U;
i32_store(i->m0,(U64)si0+12U,si1);
si0=l5;
si1=l5;
sj1=i64_load(i->m0,(U64)si1+56U);
i64_store32(i->m0,(U64)si0+8U,sj1);
si0=l5;
si1=l5;
si2=8U;
si1+=si2;
i32_store(i->m0,(U64)si0+56U,si1);
si0=l5;
si1=8U;
si0+=si1;
l20=si0;
si0=-1U;
l24=si0;
L59:;
si0=0U;
l19=si0;
si0=l20;
l21=si0;
L93:;
{
si0=l21;
si0=i32_load(i->m0,(U64)si0);
l22=si0;
si0=!(si0);
if(si0){
goto L92;
}
si0=l5;
si1=4U;
si0+=si1;
si1=l22;
si0=f40(i,si0,si1);
l22=si0;
si1=0U;
si0=(U32)((I32)si0<(I32)si1);
if(si0){
goto L2;
}
si0=l22;
si1=l24;
si2=l19;
si1-=si2;
si0=si0 > si1;
if(si0){
goto L92;
}
si0=l21;
si1=4U;
si0+=si1;
l21=si0;
si0=l22;
si1=l19;
si0+=si1;
l19=si0;
si1=l24;
si0=si0 < si1;
if(si0){
goto L93;
}
}
L92:;
si0=l19;
si1=0U;
si0=(U32)((I32)si0<(I32)si1);
if(si0){
goto L3;
}
L58:;
si0=l30;
si1=73728U;
si0&=si1;
l25=si0;
if(si0){
goto L94;
}
si0=l26;
si1=l19;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L94;
}
si0=l5;
si1=112U;
si0+=si1;
si1=32U;
si2=l26;
si3=l19;
si2-=si3;
l21=si2;
si3=256U;
si4=l21;
si5=256U;
si4=si4 < si5;
l22=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l22;
if(si0){
goto L95;
}
L96:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L97;
}
si0=l5;
si1=112U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L97:;
si0=l21;
si1=-256U;
si0+=si1;
l21=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L96;
}
}
L95:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L94;
}
si0=l5;
si1=112U;
si0+=si1;
si1=l21;
si2=l0;
si0=f34(i,si0,si1,si2);
L94:;
si0=l19;
si0=!(si0);
if(si0){
goto L98;
}
si0=0U;
l21=si0;
L99:;
{
si0=l20;
si0=i32_load(i->m0,(U64)si0);
l22=si0;
si0=!(si0);
if(si0){
goto L98;
}
si0=l5;
si1=4U;
si0+=si1;
si1=l22;
si0=f40(i,si0,si1);
l22=si0;
si1=l21;
si0+=si1;
l21=si0;
si1=l19;
si0=si0 > si1;
if(si0){
goto L98;
}
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L100;
}
si0=l5;
si1=4U;
si0+=si1;
si1=l22;
si2=l0;
si0=f34(i,si0,si1,si2);
L100:;
si0=l20;
si1=4U;
si0+=si1;
l20=si0;
si0=l21;
si1=l19;
si0=si0 < si1;
if(si0){
goto L99;
}
}
L98:;
si0=l25;
si1=8192U;
si0=si0 != si1;
if(si0){
goto L101;
}
si0=l26;
si1=l19;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L101;
}
si0=l5;
si1=112U;
si0+=si1;
si1=32U;
si2=l26;
si3=l19;
si2-=si3;
l21=si2;
si3=256U;
si4=l21;
si5=256U;
si4=si4 < si5;
l22=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l22;
if(si0){
goto L102;
}
L103:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L104;
}
si0=l5;
si1=112U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L104:;
si0=l21;
si1=-256U;
si0+=si1;
l21=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L103;
}
}
L102:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L101;
}
si0=l5;
si1=112U;
si0+=si1;
si1=l21;
si2=l0;
si0=f34(i,si0,si1,si2);
L101:;
si0=l26;
si1=l19;
si2=l26;
si3=l19;
si2=(U32)((I32)si2>(I32)si3);
si0=si2?si0:si1;
l19=si0;
goto L4;
L57:;
si0=l27;
si1=l24;
si2=0U;
si1=(U32)((I32)si1<(I32)si2);
l19=si1;
si0&=si1;
if(si0){
goto L3;
}
si0=l5;
sd0=f64_load(i->m0,(U64)si0+56U);
l34=sd0;
si0=l5;
si1=0U;
i32_store(i->m0,(U64)si0+108U,si1);
sd0=l34;
sj0=i64_reinterpret_f64(sd0);
sj1=-1ULL;
si0=(U64)((I64)sj0>(I64)sj1);
if(si0){
goto L106;
}
sd0=l34;
sd0=-(sd0);
l34=sd0;
si0=1U;
l35=si0;
si0=0U;
l36=si0;
si0=1034U;
l37=si0;
goto L105;
L106:;
si0=l30;
si1=2048U;
si0&=si1;
si0=!(si0);
if(si0){
goto L107;
}
si0=1U;
l35=si0;
si0=0U;
l36=si0;
si0=1037U;
l37=si0;
goto L105;
L107:;
si0=1040U;
si1=1035U;
si2=l30;
si3=1U;
si2&=si3;
l35=si2;
si0=si2?si0:si1;
l37=si0;
si0=l35;
si0=!(si0);
l36=si0;
L105:;
sd0=l34;
sd0=fabs(sd0);
sd1=INFINITY;
si0=sd0 < sd1;
if(si0){
goto L108;
}
si0=l35;
si1=3U;
si0+=si1;
l21=si0;
si0=l30;
si1=8192U;
si0&=si1;
if(si0){
goto L109;
}
si0=l26;
si1=l21;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L109;
}
si0=l5;
si1=624U;
si0+=si1;
si1=32U;
si2=l26;
si3=l21;
si2-=si3;
l19=si2;
si3=256U;
si4=l19;
si5=256U;
si4=si4 < si5;
l22=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l22;
if(si0){
goto L110;
}
L111:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L112;
}
si0=l5;
si1=624U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L112:;
si0=l19;
si1=-256U;
si0+=si1;
l19=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L111;
}
}
L110:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L109;
}
si0=l5;
si1=624U;
si0+=si1;
si1=l19;
si2=l0;
si0=f34(i,si0,si1,si2);
L109:;
si0=l0;
si0=i32_load(i->m0,(U64)si0);
l19=si0;
si1=32U;
si0&=si1;
if(si0){
goto L113;
}
si0=l37;
si1=l35;
si2=l0;
si0=f34(i,si0,si1,si2);
si0=l0;
si0=i32_load(i->m0,(U64)si0);
l19=si0;
L113:;
si0=l19;
si1=32U;
si0&=si1;
if(si0){
goto L114;
}
si0=1053U;
si1=1068U;
si2=l31;
si3=32U;
si2&=si3;
l19=si2;
si0=si2?si0:si1;
si1=1064U;
si2=1072U;
si3=l19;
si1=si3?si1:si2;
sd2=l34;
sd3=l34;
si2=sd2 != sd3;
si0=si2?si0:si1;
si1=3U;
si2=l0;
si0=f34(i,si0,si1,si2);
L114:;
si0=l30;
si1=73728U;
si0&=si1;
si1=8192U;
si0=si0 != si1;
if(si0){
goto L115;
}
si0=l26;
si1=l21;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L115;
}
si0=l5;
si1=624U;
si0+=si1;
si1=32U;
si2=l26;
si3=l21;
si2-=si3;
l19=si2;
si3=256U;
si4=l19;
si5=256U;
si4=si4 < si5;
l22=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l22;
if(si0){
goto L116;
}
L117:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L118;
}
si0=l5;
si1=624U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L118:;
si0=l19;
si1=-256U;
si0+=si1;
l19=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L117;
}
}
L116:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L115;
}
si0=l5;
si1=624U;
si0+=si1;
si1=l19;
si2=l0;
si0=f34(i,si0,si1,si2);
L115:;
si0=l21;
si1=l26;
si2=l21;
si3=l26;
si2=(U32)((I32)si2>(I32)si3);
si0=si2?si0:si1;
l19=si0;
goto L4;
L108:;
sd0=l34;
si1=l5;
si2=108U;
si1+=si2;
sd0=f41(i,sd0,si1);
l34=sd0;
sd1=l34;
sd0+=sd1;
l34=sd0;
sd1=0;
si0=sd0 == sd1;
if(si0){
goto L121;
}
si0=l5;
si1=l5;
si1=i32_load(i->m0,(U64)si1+108U);
l21=si1;
si2=-1U;
si1+=si2;
i32_store(i->m0,(U64)si0+108U,si1);
si0=l31;
si1=32U;
si0|=si1;
l38=si0;
si1=97U;
si0=si0 != si1;
if(si0){
goto L120;
}
goto L6;
L121:;
si0=l31;
si1=32U;
si0|=si1;
l38=si0;
si1=97U;
si0=si0 == si1;
if(si0){
goto L6;
}
si0=6U;
si1=l24;
si2=l19;
si0=si2?si0:si1;
l27=si0;
si0=l5;
si0=i32_load(i->m0,(U64)si0+108U);
l20=si0;
goto L119;
L120:;
si0=l5;
si1=l21;
si2=-29U;
si1+=si2;
l20=si1;
i32_store(i->m0,(U64)si0+108U,si1);
si0=6U;
si1=l24;
si2=l19;
si0=si2?si0:si1;
l27=si0;
sd0=l34;
sd1=268435456;
sd0*=sd1;
l34=sd0;
L119:;
si0=l5;
si1=112U;
si0+=si1;
si1=0U;
si2=72U;
si3=l20;
si4=0U;
si3=(U32)((I32)si3<(I32)si4);
l39=si3;
si1=si3?si1:si2;
si2=2U;
si1<<=(si2&31);
l40=si1;
si0+=si1;
l23=si0;
l21=si0;
L122:;
{
sd0=l34;
sd1=4294967296;
si0=sd0 < sd1;
sd1=l34;
sd2=0;
si1=sd1 >= sd2;
si0&=si1;
si0=!(si0);
if(si0){
goto L124;
}
sd0=l34;
si0=I32_TRUNC_U_F64(sd0);
l19=si0;
goto L123;
L124:;
si0=0U;
l19=si0;
L123:;
si0=l21;
si1=l19;
i32_store(i->m0,(U64)si0,si1);
si0=l21;
si1=4U;
si0+=si1;
l21=si0;
sd0=l34;
si1=l19;
sd1=(F64)(si1);
sd0-=sd1;
sd1=1000000000;
sd0*=sd1;
l34=sd0;
sd1=0;
si0=sd0 != sd1;
if(si0){
goto L122;
}
}
si0=l20;
si1=1U;
si0=(U32)((I32)si0>=(I32)si1);
if(si0){
goto L126;
}
si0=l21;
l19=si0;
si0=l23;
l22=si0;
goto L125;
L126:;
si0=l23;
l22=si0;
L127:;
{
si0=l20;
si1=29U;
si2=l20;
si3=29U;
si2=(U32)((I32)si2<(I32)si3);
si0=si2?si0:si1;
l20=si0;
si0=l21;
si1=-4U;
si0+=si1;
l19=si0;
si1=l22;
si0=si0 < si1;
if(si0){
goto L128;
}
si0=l20;
sj0=(U64)(si0);
l33=sj0;
sj0=0ULL;
l32=sj0;
L129:;
{
si0=l19;
si1=l19;
sj1=i64_load32_u(i->m0,(U64)si1);
sj2=l33;
sj1<<=(sj2&63);
sj2=l32;
sj3=4294967295ULL;
sj2&=sj3;
sj1+=sj2;
l32=sj1;
sj2=l32;
sj3=1000000000ULL;
sj2=DIV_U(sj2,sj3);
l32=sj2;
sj3=1000000000ULL;
sj2*=sj3;
sj1-=sj2;
i64_store32(i->m0,(U64)si0,sj1);
si0=l19;
si1=-4U;
si0+=si1;
l19=si0;
si1=l22;
si0=si0 >= si1;
if(si0){
goto L129;
}
}
sj0=l32;
si0=(U32)(sj0);
l19=si0;
si0=!(si0);
if(si0){
goto L128;
}
si0=l22;
si1=-4U;
si0+=si1;
l22=si0;
si1=l19;
i32_store(i->m0,(U64)si0,si1);
L128:;
L131:;
{
si0=l21;
l19=si0;
si1=l22;
si0=si0 <= si1;
if(si0){
goto L130;
}
si0=l19;
si1=-4U;
si0+=si1;
l21=si0;
si0=i32_load(i->m0,(U64)si0);
si0=!(si0);
if(si0){
goto L131;
}
}
L130:;
si0=l5;
si1=l5;
si1=i32_load(i->m0,(U64)si1+108U);
si2=l20;
si1-=si2;
l20=si1;
i32_store(i->m0,(U64)si0+108U,si1);
si0=l19;
l21=si0;
si0=l20;
si1=0U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L127;
}
}
L125:;
si0=l20;
si1=-1U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L132;
}
si0=l27;
si1=25U;
si0+=si1;
si1=9U;
si0=DIV_U(si0,si1);
si1=1U;
si0+=si1;
l41=si0;
si0=l38;
si1=102U;
si0=si0 == si1;
l42=si0;
L133:;
{
si0=0U;
si1=l20;
si0-=si1;
l21=si0;
si1=9U;
si2=l21;
si3=9U;
si2=(U32)((I32)si2<(I32)si3);
si0=si2?si0:si1;
l24=si0;
si0=l22;
si1=l19;
si0=si0 < si1;
if(si0){
goto L135;
}
si0=l22;
si0=i32_load(i->m0,(U64)si0);
l21=si0;
goto L134;
L135:;
si0=1000000000U;
si1=l24;
si0>>=(si1&31);
l29=si0;
si0=-1U;
si1=l24;
si0<<=(si1&31);
si1=-1U;
si0^=si1;
l28=si0;
si0=0U;
l20=si0;
si0=l22;
l21=si0;
L136:;
{
si0=l21;
si1=l21;
si1=i32_load(i->m0,(U64)si1);
l25=si1;
si2=l24;
si1>>=(si2&31);
si2=l20;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l25;
si1=l28;
si0&=si1;
si1=l29;
si0*=si1;
l20=si0;
si0=l21;
si1=4U;
si0+=si1;
l21=si0;
si1=l19;
si0=si0 < si1;
if(si0){
goto L136;
}
}
si0=l22;
si0=i32_load(i->m0,(U64)si0);
l21=si0;
si0=l20;
si0=!(si0);
if(si0){
goto L134;
}
si0=l19;
si1=l20;
i32_store(i->m0,(U64)si0,si1);
si0=l19;
si1=4U;
si0+=si1;
l19=si0;
L134:;
si0=l5;
si1=l5;
si1=i32_load(i->m0,(U64)si1+108U);
si2=l24;
si1+=si2;
l20=si1;
i32_store(i->m0,(U64)si0+108U,si1);
si0=l23;
si1=l22;
si2=l21;
si2=!(si2);
si3=2U;
si2<<=(si3&31);
si1+=si2;
l22=si1;
si2=l42;
si0=si2?si0:si1;
l21=si0;
si1=l41;
si2=2U;
si1<<=(si2&31);
si0+=si1;
si1=l19;
si2=l19;
si3=l21;
si2-=si3;
si3=2U;
si2=(U32)((I32)si2>>(si3&31));
si3=l41;
si2=(U32)((I32)si2>(I32)si3);
si0=si2?si0:si1;
l19=si0;
si0=l20;
si1=0U;
si0=(U32)((I32)si0<(I32)si1);
if(si0){
goto L133;
}
}
L132:;
si0=0U;
l25=si0;
si0=l22;
si1=l19;
si0=si0 >= si1;
if(si0){
goto L137;
}
si0=l23;
si1=l22;
si0-=si1;
si1=2U;
si0=(U32)((I32)si0>>(si1&31));
si1=9U;
si0*=si1;
l25=si0;
si0=l22;
si0=i32_load(i->m0,(U64)si0);
l20=si0;
si1=10U;
si0=si0 < si1;
if(si0){
goto L137;
}
si0=10U;
l21=si0;
L138:;
{
si0=l25;
si1=1U;
si0+=si1;
l25=si0;
si0=l20;
si1=l21;
si2=10U;
si1*=si2;
l21=si1;
si0=si0 >= si1;
if(si0){
goto L138;
}
}
L137:;
si0=l27;
si1=0U;
si2=l25;
si3=l38;
si4=102U;
si3=si3 == si4;
si1=si3?si1:si2;
si0-=si1;
si1=l27;
si2=0U;
si1=si1 != si2;
si2=l38;
si3=103U;
si2=si2 == si3;
l28=si2;
si1&=si2;
si0-=si1;
l21=si0;
si1=l19;
si2=l23;
si1-=si2;
si2=2U;
si1=(U32)((I32)si1>>(si2&31));
si2=9U;
si1*=si2;
si2=-9U;
si1+=si2;
si0=(U32)((I32)si0>=(I32)si1);
if(si0){
goto L139;
}
si0=l5;
si1=112U;
si0+=si1;
si1=1U;
si2=73U;
si3=l39;
si1=si3?si1:si2;
si2=2U;
si1<<=(si2&31);
l39=si1;
si0+=si1;
si1=l21;
si2=9216U;
si1+=si2;
l20=si1;
si2=9U;
si1=I32_DIV_S(si1,si2);
l24=si1;
si2=2U;
si1<<=(si2&31);
l43=si1;
si0+=si1;
l42=si0;
si1=-4096U;
si0+=si1;
l29=si0;
si0=10U;
l21=si0;
si0=l20;
si1=l24;
si2=9U;
si1*=si2;
si0-=si1;
l24=si0;
si1=7U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L140;
}
si0=8U;
si1=l24;
si0-=si1;
l41=si0;
si1=7U;
si0&=si1;
l20=si0;
si0=10U;
l21=si0;
si0=l24;
si1=-1U;
si0+=si1;
si1=7U;
si0=si0 < si1;
if(si0){
goto L141;
}
si0=l41;
si1=-8U;
si0&=si1;
l24=si0;
si0=10U;
l21=si0;
L142:;
{
si0=l21;
si1=100000000U;
si0*=si1;
l21=si0;
si0=l24;
si1=-8U;
si0+=si1;
l24=si0;
if(si0){
goto L142;
}
}
L141:;
si0=l20;
si0=!(si0);
if(si0){
goto L140;
}
L143:;
{
si0=l21;
si1=10U;
si0*=si1;
l21=si0;
si0=l20;
si1=-1U;
si0+=si1;
l20=si0;
if(si0){
goto L143;
}
}
L140:;
si0=l42;
si1=-4092U;
si0+=si1;
l41=si0;
si0=l29;
si0=i32_load(i->m0,(U64)si0);
l20=si0;
si1=l20;
si2=l21;
si1=DIV_U(si1,si2);
l38=si1;
si2=l21;
si1*=si2;
si0-=si1;
l24=si0;
if(si0){
goto L145;
}
si0=l41;
si1=l19;
si0=si0 == si1;
if(si0){
goto L144;
}
L145:;
si0=l38;
si1=1U;
si0&=si1;
if(si0){
goto L147;
}
sd0=9007199254740992;
l34=sd0;
si0=l21;
si1=1000000000U;
si0=si0 != si1;
if(si0){
goto L146;
}
si0=l29;
si1=l22;
si0=si0 <= si1;
if(si0){
goto L146;
}
si0=l42;
si1=-4100U;
si0+=si1;
si0=i32_load8_u(i->m0,(U64)si0);
si1=1U;
si0&=si1;
si0=!(si0);
if(si0){
goto L146;
}
L147:;
sd0=9007199254740994;
l34=sd0;
L146:;
sd0=0.5;
sd1=1;
sd2=1.5;
si3=l41;
si4=l19;
si3=si3 == si4;
sd1=si3?sd1:sd2;
sd2=1.5;
si3=l24;
si4=l21;
si5=1U;
si4>>=(si5&31);
l41=si4;
si3=si3 == si4;
sd1=si3?sd1:sd2;
si2=l24;
si3=l41;
si2=si2 < si3;
sd0=si2?sd0:sd1;
l44=sd0;
si0=l36;
if(si0){
goto L148;
}
si0=l37;
si0=i32_load8_u(i->m0,(U64)si0);
si1=45U;
si0=si0 != si1;
if(si0){
goto L148;
}
sd0=l44;
sd0=-(sd0);
l44=sd0;
sd0=l34;
sd0=-(sd0);
l34=sd0;
L148:;
si0=l29;
si1=l20;
si2=l24;
si1-=si2;
l20=si1;
i32_store(i->m0,(U64)si0,si1);
sd0=l34;
sd1=l44;
sd0+=sd1;
sd1=l34;
si0=sd0 == sd1;
if(si0){
goto L144;
}
si0=l29;
si1=l20;
si2=l21;
si1+=si2;
l21=si1;
i32_store(i->m0,(U64)si0,si1);
si0=l21;
si1=1000000000U;
si0=si0 < si1;
if(si0){
goto L149;
}
si0=l9;
si1=l39;
si2=l43;
si1+=si2;
si0+=si1;
l21=si0;
L150:;
{
si0=l21;
si1=4U;
si0+=si1;
si1=0U;
i32_store(i->m0,(U64)si0,si1);
si0=l21;
si1=l22;
si0=si0 >= si1;
if(si0){
goto L151;
}
si0=l22;
si1=-4U;
si0+=si1;
l22=si0;
si1=0U;
i32_store(i->m0,(U64)si0,si1);
L151:;
si0=l21;
si1=l21;
si1=i32_load(i->m0,(U64)si1);
si2=1U;
si1+=si2;
l20=si1;
i32_store(i->m0,(U64)si0,si1);
si0=l21;
si1=-4U;
si0+=si1;
l21=si0;
si0=l20;
si1=999999999U;
si0=si0 > si1;
if(si0){
goto L150;
}
}
si0=l21;
si1=4U;
si0+=si1;
l29=si0;
L149:;
si0=l23;
si1=l22;
si0-=si1;
si1=2U;
si0=(U32)((I32)si0>>(si1&31));
si1=9U;
si0*=si1;
l25=si0;
si0=l22;
si0=i32_load(i->m0,(U64)si0);
l20=si0;
si1=10U;
si0=si0 < si1;
if(si0){
goto L144;
}
si0=10U;
l21=si0;
L152:;
{
si0=l25;
si1=1U;
si0+=si1;
l25=si0;
si0=l20;
si1=l21;
si2=10U;
si1*=si2;
l21=si1;
si0=si0 >= si1;
if(si0){
goto L152;
}
}
L144:;
si0=l29;
si1=4U;
si0+=si1;
l21=si0;
si1=l19;
si2=l19;
si3=l21;
si2=si2 > si3;
si0=si2?si0:si1;
l19=si0;
L139:;
si0=l8;
si1=l19;
si0+=si1;
si1=l40;
si0-=si1;
l21=si0;
L154:;
{
si0=l21;
l20=si0;
si0=l19;
l29=si0;
si1=l22;
si0=si0 <= si1;
l24=si0;
if(si0){
goto L153;
}
si0=l20;
si1=-4U;
si0+=si1;
l21=si0;
si0=l29;
si1=-4U;
si0+=si1;
l19=si0;
si0=i32_load(i->m0,(U64)si0);
si0=!(si0);
if(si0){
goto L154;
}
}
L153:;
si0=l28;
if(si0){
goto L156;
}
si0=l30;
si1=8U;
si0&=si1;
l41=si0;
goto L155;
L156:;
si0=l25;
si1=-1U;
si0^=si1;
si1=-1U;
si2=l27;
si3=1U;
si4=l27;
si2=si4?si2:si3;
l19=si2;
si3=l25;
si2=(U32)((I32)si2>(I32)si3);
si3=l25;
si4=-5U;
si3=(U32)((I32)si3>(I32)si4);
si2&=si3;
l21=si2;
si0=si2?si0:si1;
si1=l19;
si0+=si1;
l27=si0;
si0=-1U;
si1=-2U;
si2=l21;
si0=si2?si0:si1;
si1=l31;
si0+=si1;
l31=si0;
si0=l30;
si1=8U;
si0&=si1;
l41=si0;
if(si0){
goto L155;
}
si0=-9U;
l19=si0;
si0=l24;
if(si0){
goto L157;
}
si0=l29;
si1=-4U;
si0+=si1;
si0=i32_load(i->m0,(U64)si0);
l24=si0;
si0=!(si0);
if(si0){
goto L157;
}
si0=0U;
l19=si0;
si0=l24;
si1=10U;
si0=REM_U(si0,si1);
if(si0){
goto L157;
}
si0=10U;
l21=si0;
si0=0U;
l19=si0;
L158:;
{
si0=l19;
si1=-1U;
si0+=si1;
l19=si0;
si0=l24;
si1=l21;
si2=10U;
si1*=si2;
l21=si1;
si0=REM_U(si0,si1);
si0=!(si0);
if(si0){
goto L158;
}
}
L157:;
si0=l20;
si1=2U;
si0=(U32)((I32)si0>>(si1&31));
si1=9U;
si0*=si1;
l21=si0;
si0=l31;
si1=-33U;
si0&=si1;
si1=70U;
si0=si0 != si1;
if(si0){
goto L159;
}
si0=0U;
l41=si0;
si0=l27;
si1=l21;
si2=l19;
si1+=si2;
si2=-9U;
si1+=si2;
l19=si1;
si2=0U;
si3=l19;
si4=0U;
si3=(U32)((I32)si3>(I32)si4);
si1=si3?si1:si2;
l19=si1;
si2=l27;
si3=l19;
si2=(U32)((I32)si2<(I32)si3);
si0=si2?si0:si1;
l27=si0;
goto L155;
L159:;
si0=0U;
l41=si0;
si0=l27;
si1=l25;
si2=l21;
si1+=si2;
si2=l19;
si1+=si2;
si2=-9U;
si1+=si2;
l19=si1;
si2=0U;
si3=l19;
si4=0U;
si3=(U32)((I32)si3>(I32)si4);
si1=si3?si1:si2;
l19=si1;
si2=l27;
si3=l19;
si2=(U32)((I32)si2<(I32)si3);
si0=si2?si0:si1;
l27=si0;
L155:;
si0=l27;
si1=2147483645U;
si2=2147483646U;
si3=l27;
si4=l41;
si3|=si4;
l38=si3;
si1=si3?si1:si2;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L3;
}
si0=l27;
si1=l38;
si2=0U;
si1=si1 != si2;
si0+=si1;
si1=1U;
si0+=si1;
l42=si0;
si0=l31;
si1=-33U;
si0&=si1;
si1=70U;
si0=si0 != si1;
l40=si0;
if(si0){
goto L161;
}
si0=l25;
si1=l42;
si2=2147483647U;
si1^=si2;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L3;
}
si0=l25;
si1=0U;
si2=l25;
si3=0U;
si2=(U32)((I32)si2>(I32)si3);
si0=si2?si0:si1;
l19=si0;
goto L160;
L161:;
si0=l25;
if(si0){
goto L163;
}
si0=l7;
l20=si0;
si0=l7;
l21=si0;
goto L162;
L163:;
si0=l25;
si1=l25;
si2=31U;
si1=(U32)((I32)si1>>(si2&31));
l19=si1;
si0^=si1;
si1=l19;
si0-=si1;
l19=si0;
si0=l7;
l20=si0;
si0=l7;
l21=si0;
L164:;
{
si0=l21;
si1=-1U;
si0+=si1;
l21=si0;
si1=l19;
si2=l19;
si3=10U;
si2=DIV_U(si2,si3);
l24=si2;
si3=10U;
si2*=si3;
si1-=si2;
si2=48U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l20;
si1=-1U;
si0+=si1;
l20=si0;
si0=l19;
si1=9U;
si0=si0 > si1;
l28=si0;
si0=l24;
l19=si0;
si0=l28;
if(si0){
goto L164;
}
}
L162:;
si0=l7;
si1=l20;
si0-=si1;
si1=1U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L165;
}
si0=l21;
si1=l15;
si2=l20;
si1-=si2;
si0+=si1;
l21=si0;
si1=48U;
si2=l20;
si3=l5;
si4=68U;
si3+=si4;
si2-=si3;
si3=-10U;
si2+=si3;
si0=f50(i,si0,si1,si2);
L165:;
si0=l21;
si1=-2U;
si0+=si1;
l36=si0;
si1=l31;
i32_store8(i->m0,(U64)si0,si1);
si0=l21;
si1=-1U;
si0+=si1;
si1=45U;
si2=43U;
si3=l25;
si4=0U;
si3=(U32)((I32)si3<(I32)si4);
si1=si3?si1:si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l7;
si1=l36;
si0-=si1;
l19=si0;
si1=l42;
si2=2147483647U;
si1^=si2;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L3;
}
L160:;
si0=l19;
si1=l42;
si0+=si1;
l19=si0;
si1=l35;
si2=2147483647U;
si1^=si2;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L3;
}
si0=l19;
si1=l35;
si0+=si1;
l28=si0;
si0=l30;
si1=73728U;
si0&=si1;
l30=si0;
if(si0){
goto L166;
}
si0=l26;
si1=l28;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L166;
}
si0=l5;
si1=624U;
si0+=si1;
si1=32U;
si2=l26;
si3=l28;
si2-=si3;
l19=si2;
si3=256U;
si4=l19;
si5=256U;
si4=si4 < si5;
l21=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l21;
if(si0){
goto L167;
}
L168:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L169;
}
si0=l5;
si1=624U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L169:;
si0=l19;
si1=-256U;
si0+=si1;
l19=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L168;
}
}
L167:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L166;
}
si0=l5;
si1=624U;
si0+=si1;
si1=l19;
si2=l0;
si0=f34(i,si0,si1,si2);
L166:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L170;
}
si0=l37;
si1=l35;
si2=l0;
si0=f34(i,si0,si1,si2);
L170:;
si0=l30;
si1=65536U;
si0=si0 != si1;
if(si0){
goto L171;
}
si0=l26;
si1=l28;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L171;
}
si0=l5;
si1=624U;
si0+=si1;
si1=48U;
si2=l26;
si3=l28;
si2-=si3;
l19=si2;
si3=256U;
si4=l19;
si5=256U;
si4=si4 < si5;
l21=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l21;
if(si0){
goto L172;
}
L173:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L174;
}
si0=l5;
si1=624U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L174:;
si0=l19;
si1=-256U;
si0+=si1;
l19=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L173;
}
}
L172:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L171;
}
si0=l5;
si1=624U;
si0+=si1;
si1=l19;
si2=l0;
si0=f34(i,si0,si1,si2);
L171:;
si0=l40;
if(si0){
goto L8;
}
si0=l23;
si1=l22;
si2=l22;
si3=l23;
si2=si2 > si3;
si0=si2?si0:si1;
l25=si0;
l24=si0;
L175:;
{
si0=l24;
si0=i32_load(i->m0,(U64)si0);
l19=si0;
si0=!(si0);
if(si0){
goto L179;
}
si0=8U;
l21=si0;
L180:;
{
si0=l5;
si1=80U;
si0+=si1;
si1=l21;
si0+=si1;
si1=l19;
si2=l19;
si3=10U;
si2=DIV_U(si2,si3);
l22=si2;
si3=10U;
si2*=si3;
si1-=si2;
si2=48U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l21;
si1=-1U;
si0+=si1;
l21=si0;
si0=l19;
si1=9U;
si0=si0 > si1;
l20=si0;
si0=l22;
l19=si0;
si0=l20;
if(si0){
goto L180;
}
}
si0=l21;
si1=1U;
si0+=si1;
l22=si0;
si1=l5;
si2=80U;
si1+=si2;
si0+=si1;
l19=si0;
si0=l24;
si1=l25;
si0=si0 == si1;
if(si0){
goto L181;
}
si0=l21;
si1=2U;
si0+=si1;
si1=2U;
si0=(U32)((I32)si0<(I32)si1);
if(si0){
goto L176;
}
goto L177;
L181:;
si0=l21;
si1=8U;
si0=si0 != si1;
if(si0){
goto L176;
}
goto L178;
L179:;
si0=9U;
l22=si0;
si0=l24;
si1=l25;
si0=si0 != si1;
if(si0){
goto L177;
}
L178:;
si0=l5;
si1=48U;
i32_store8(i->m0,(U64)si0+88U,si1);
si0=l13;
l19=si0;
goto L176;
L177:;
si0=l5;
si1=80U;
si0+=si1;
si1=l12;
si2=l22;
si1+=si2;
l19=si1;
si2=l5;
si3=80U;
si2+=si3;
si3=l19;
si2=si2 < si3;
si0=si2?si0:si1;
l19=si0;
si1=48U;
si2=l22;
si3=l5;
si4=80U;
si3+=si4;
si2+=si3;
si3=l19;
si2-=si3;
si0=f50(i,si0,si1,si2);
L176:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L182;
}
si0=l19;
si1=l14;
si2=l19;
si1-=si2;
si2=l0;
si0=f34(i,si0,si1,si2);
L182:;
si0=l24;
si1=4U;
si0+=si1;
l24=si0;
si1=l23;
si0=si0 <= si1;
if(si0){
goto L175;
}
}
si0=l38;
si0=!(si0);
if(si0){
goto L183;
}
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L183;
}
si0=1076U;
si1=1U;
si2=l0;
si0=f34(i,si0,si1,si2);
L183:;
si0=l27;
si1=1U;
si0=(U32)((I32)si0>=(I32)si1);
if(si0){
goto L185;
}
si0=l27;
l19=si0;
goto L184;
L185:;
si0=l24;
si1=l29;
si0=si0 < si1;
if(si0){
goto L186;
}
si0=l27;
l19=si0;
goto L184;
L186:;
L187:;
{
si0=l24;
si0=i32_load(i->m0,(U64)si0);
l19=si0;
if(si0){
goto L190;
}
si0=l14;
l21=si0;
si0=l14;
l22=si0;
goto L189;
L190:;
si0=l14;
l22=si0;
si0=l14;
l21=si0;
L191:;
{
si0=l21;
si1=-1U;
si0+=si1;
l21=si0;
si1=l19;
si2=l19;
si3=10U;
si2=DIV_U(si2,si3);
l20=si2;
si3=10U;
si2*=si3;
si1-=si2;
si2=48U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l22;
si1=-1U;
si0+=si1;
l22=si0;
si0=l19;
si1=9U;
si0=si0 > si1;
l25=si0;
si0=l20;
l19=si0;
si0=l25;
if(si0){
goto L191;
}
}
si0=l21;
si1=l5;
si2=80U;
si1+=si2;
si0=si0 <= si1;
if(si0){
goto L188;
}
L189:;
si0=l21;
si1=l5;
si2=80U;
si1+=si2;
si0+=si1;
si1=l22;
si0-=si1;
l21=si0;
si1=48U;
si2=l22;
si3=l5;
si4=80U;
si3+=si4;
si2-=si3;
si0=f50(i,si0,si1,si2);
L188:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L192;
}
si0=l21;
si1=l27;
si2=9U;
si3=l27;
si4=9U;
si3=(U32)((I32)si3<(I32)si4);
si1=si3?si1:si2;
si2=l0;
si0=f34(i,si0,si1,si2);
L192:;
si0=l27;
si1=-9U;
si0+=si1;
l19=si0;
si0=l24;
si1=4U;
si0+=si1;
l24=si0;
si1=l29;
si0=si0 >= si1;
if(si0){
goto L184;
}
si0=l27;
si1=9U;
si0=(U32)((I32)si0>(I32)si1);
l21=si0;
si0=l19;
l27=si0;
si0=l21;
if(si0){
goto L187;
}
}
L184:;
si0=l0;
si1=48U;
si2=l19;
si3=9U;
si2+=si3;
si3=9U;
si4=0U;
f47(i,si0,si1,si2,si3,si4);
goto L7;
L11:;
si0=3700U;
si1=28U;
i32_store(i->m0,(U64)si0,si1);
goto L2;
L10:;
si0=0U;
l28=si0;
si0=1024U;
l23=si0;
si0=l16;
l19=si0;
si0=l30;
l29=si0;
si0=l24;
l25=si0;
L9:;
si0=l25;
si1=l19;
si2=l20;
si1-=si2;
l24=si1;
si2=l25;
si3=l24;
si2=(U32)((I32)si2>(I32)si3);
si0=si2?si0:si1;
l27=si0;
si1=l28;
si2=2147483647U;
si1^=si2;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L3;
}
si0=l26;
si1=l28;
si2=l27;
si1+=si2;
l22=si1;
si2=l26;
si3=l22;
si2=(U32)((I32)si2>(I32)si3);
si0=si2?si0:si1;
l19=si0;
si1=l21;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L3;
}
si0=l29;
si1=73728U;
si0&=si1;
l29=si0;
if(si0){
goto L193;
}
si0=l26;
si1=l22;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L193;
}
si0=l5;
si1=112U;
si0+=si1;
si1=32U;
si2=l19;
si3=l22;
si2-=si3;
l21=si2;
si3=256U;
si4=l21;
si5=256U;
si4=si4 < si5;
l30=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l30;
if(si0){
goto L194;
}
L195:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L196;
}
si0=l5;
si1=112U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L196:;
si0=l21;
si1=-256U;
si0+=si1;
l21=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L195;
}
}
L194:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L193;
}
si0=l5;
si1=112U;
si0+=si1;
si1=l21;
si2=l0;
si0=f34(i,si0,si1,si2);
L193:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L197;
}
si0=l23;
si1=l28;
si2=l0;
si0=f34(i,si0,si1,si2);
L197:;
si0=l29;
si1=65536U;
si0=si0 != si1;
if(si0){
goto L198;
}
si0=l26;
si1=l22;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L198;
}
si0=l5;
si1=112U;
si0+=si1;
si1=48U;
si2=l19;
si3=l22;
si2-=si3;
l21=si2;
si3=256U;
si4=l21;
si5=256U;
si4=si4 < si5;
l28=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l28;
if(si0){
goto L199;
}
L200:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L201;
}
si0=l5;
si1=112U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L201:;
si0=l21;
si1=-256U;
si0+=si1;
l21=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L200;
}
}
L199:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L198;
}
si0=l5;
si1=112U;
si0+=si1;
si1=l21;
si2=l0;
si0=f34(i,si0,si1,si2);
L198:;
si0=l25;
si1=l24;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L202;
}
si0=l5;
si1=112U;
si0+=si1;
si1=48U;
si2=l27;
si3=l24;
si2-=si3;
l21=si2;
si3=256U;
si4=l21;
si5=256U;
si4=si4 < si5;
l25=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l25;
if(si0){
goto L203;
}
L204:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L205;
}
si0=l5;
si1=112U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L205:;
si0=l21;
si1=-256U;
si0+=si1;
l21=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L204;
}
}
L203:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L202;
}
si0=l5;
si1=112U;
si0+=si1;
si1=l21;
si2=l0;
si0=f34(i,si0,si1,si2);
L202:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L206;
}
si0=l20;
si1=l24;
si2=l0;
si0=f34(i,si0,si1,si2);
L206:;
si0=l29;
si1=8192U;
si0=si0 != si1;
if(si0){
goto L4;
}
si0=l26;
si1=l22;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L4;
}
si0=l5;
si1=112U;
si0+=si1;
si1=32U;
si2=l19;
si3=l22;
si2-=si3;
l21=si2;
si3=256U;
si4=l21;
si5=256U;
si4=si4 < si5;
l22=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l22;
if(si0){
goto L207;
}
L208:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L209;
}
si0=l5;
si1=112U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L209:;
si0=l21;
si1=-256U;
si0+=si1;
l21=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L208;
}
}
L207:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L4;
}
si0=l5;
si1=112U;
si0+=si1;
si1=l21;
si2=l0;
si0=f34(i,si0,si1,si2);
goto L4;
L8:;
si0=l27;
si1=0U;
si0=(U32)((I32)si0<(I32)si1);
if(si0){
goto L210;
}
si0=l29;
si1=l22;
si2=4U;
si1+=si2;
si2=l29;
si3=l22;
si2=si2 > si3;
si0=si2?si0:si1;
l29=si0;
si0=l22;
l24=si0;
L211:;
{
si0=l24;
si0=i32_load(i->m0,(U64)si0);
l19=si0;
si0=!(si0);
if(si0){
goto L213;
}
si0=l14;
l21=si0;
L214:;
{
si0=l21;
si1=-1U;
si0+=si1;
l21=si0;
si1=l19;
si2=l19;
si3=10U;
si2=DIV_U(si2,si3);
l20=si2;
si3=10U;
si2*=si3;
si1-=si2;
si2=48U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l19;
si1=10U;
si0=si0 < si1;
l25=si0;
si0=l20;
l19=si0;
si0=l25;
si0=!(si0);
if(si0){
goto L214;
}
goto L212;
}
L213:;
si0=l5;
si1=48U;
i32_store8(i->m0,(U64)si0+88U,si1);
si0=l13;
l21=si0;
L212:;
si0=l24;
si1=l22;
si0=si0 == si1;
if(si0){
goto L216;
}
si0=l21;
si1=l5;
si2=80U;
si1+=si2;
si0=si0 <= si1;
if(si0){
goto L215;
}
si0=l5;
si1=80U;
si0+=si1;
si1=48U;
si2=l21;
si3=l5;
si4=80U;
si3+=si4;
si2-=si3;
si0=f50(i,si0,si1,si2);
si0=l5;
si1=80U;
si0+=si1;
l21=si0;
goto L215;
L216:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L217;
}
si0=l21;
si1=1U;
si2=l0;
si0=f34(i,si0,si1,si2);
L217:;
si0=l21;
si1=1U;
si0+=si1;
l21=si0;
si0=l41;
if(si0){
goto L218;
}
si0=l27;
si1=1U;
si0=(U32)((I32)si0<(I32)si1);
if(si0){
goto L215;
}
L218:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L215;
}
si0=1076U;
si1=1U;
si2=l0;
si0=f34(i,si0,si1,si2);
L215:;
si0=l14;
si1=l21;
si0-=si1;
l19=si0;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L219;
}
si0=l21;
si1=l19;
si2=l27;
si3=l19;
si4=l27;
si3=(U32)((I32)si3<(I32)si4);
si1=si3?si1:si2;
si2=l0;
si0=f34(i,si0,si1,si2);
L219:;
si0=l27;
si1=l19;
si0-=si1;
l27=si0;
si0=l24;
si1=4U;
si0+=si1;
l24=si0;
si1=l29;
si0=si0 >= si1;
if(si0){
goto L210;
}
si0=l27;
si1=-1U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L211;
}
}
L210:;
si0=l0;
si1=48U;
si2=l27;
si3=18U;
si2+=si3;
si3=18U;
si4=0U;
f47(i,si0,si1,si2,si3,si4);
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L7;
}
si0=l36;
si1=l7;
si2=l36;
si1-=si2;
si2=l0;
si0=f34(i,si0,si1,si2);
L7:;
si0=l30;
si1=8192U;
si0=si0 != si1;
if(si0){
goto L5;
}
si0=l26;
si1=l28;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L5;
}
si0=l5;
si1=624U;
si0+=si1;
si1=32U;
si2=l26;
si3=l28;
si2-=si3;
l19=si2;
si3=256U;
si4=l19;
si5=256U;
si4=si4 < si5;
l21=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l21;
if(si0){
goto L220;
}
L221:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L222;
}
si0=l5;
si1=624U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L222:;
si0=l19;
si1=-256U;
si0+=si1;
l19=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L221;
}
}
L220:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L5;
}
si0=l5;
si1=624U;
si0+=si1;
si1=l19;
si2=l0;
si0=f34(i,si0,si1,si2);
goto L5;
L6:;
si0=l37;
si1=l31;
si2=26U;
si1<<=(si2&31);
si2=31U;
si1=(U32)((I32)si1>>(si2&31));
si2=9U;
si1&=si2;
si0+=si1;
l23=si0;
si0=l24;
si1=11U;
si0=si0 > si1;
if(si0){
goto L223;
}
si0=12U;
si1=l24;
si0-=si1;
l19=si0;
si1=7U;
si0&=si1;
l21=si0;
if(si0){
goto L225;
}
sd0=16;
l44=sd0;
goto L224;
L225:;
si0=l24;
si1=-12U;
si0+=si1;
l19=si0;
sd0=16;
l44=sd0;
L226:;
{
si0=l19;
si1=1U;
si0+=si1;
l19=si0;
sd0=l44;
sd1=16;
sd0*=sd1;
l44=sd0;
si0=l21;
si1=-1U;
si0+=si1;
l21=si0;
if(si0){
goto L226;
}
}
si0=0U;
si1=l19;
si0-=si1;
l19=si0;
L224:;
si0=l24;
si1=-5U;
si0+=si1;
si1=7U;
si0=si0 < si1;
if(si0){
goto L227;
}
L228:;
{
sd0=l44;
sd1=16;
sd0*=sd1;
sd1=16;
sd0*=sd1;
sd1=16;
sd0*=sd1;
sd1=16;
sd0*=sd1;
sd1=16;
sd0*=sd1;
sd1=16;
sd0*=sd1;
sd1=16;
sd0*=sd1;
sd1=16;
sd0*=sd1;
l44=sd0;
si0=l19;
si1=-8U;
si0+=si1;
l19=si0;
if(si0){
goto L228;
}
}
L227:;
si0=l23;
si0=i32_load8_u(i->m0,(U64)si0);
si1=45U;
si0=si0 != si1;
if(si0){
goto L229;
}
sd0=l44;
sd1=l34;
sd1=-(sd1);
sd2=l44;
sd1-=sd2;
sd0+=sd1;
sd0=-(sd0);
l34=sd0;
goto L223;
L229:;
sd0=l34;
sd1=l44;
sd0+=sd1;
sd1=l44;
sd0-=sd1;
l34=sd0;
L223:;
si0=l5;
si0=i32_load(i->m0,(U64)si0+108U);
l25=si0;
si0=!(si0);
if(si0){
goto L231;
}
si0=l25;
si1=l25;
si2=31U;
si1=(U32)((I32)si1>>(si2&31));
l19=si1;
si0^=si1;
si1=l19;
si0-=si1;
l19=si0;
si0=l7;
l21=si0;
L232:;
{
si0=l21;
si1=-1U;
si0+=si1;
l21=si0;
si1=l19;
si2=l19;
si3=10U;
si2=DIV_U(si2,si3);
l22=si2;
si3=10U;
si2*=si3;
si1-=si2;
si2=48U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l19;
si1=10U;
si0=si0 < si1;
l20=si0;
si0=l22;
l19=si0;
si0=l20;
si0=!(si0);
if(si0){
goto L232;
}
goto L230;
}
L231:;
si0=l5;
si1=48U;
i32_store8(i->m0,(U64)si0+79U,si1);
si0=l11;
l21=si0;
L230:;
si0=l35;
si1=2U;
si0|=si1;
l29=si0;
si0=l31;
si1=32U;
si0&=si1;
l22=si0;
si0=l21;
si1=-2U;
si0+=si1;
l27=si0;
si1=l31;
si2=15U;
si1+=si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l21;
si1=-1U;
si0+=si1;
si1=45U;
si2=43U;
si3=l25;
si4=0U;
si3=(U32)((I32)si3<(I32)si4);
si1=si3?si1:si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l30;
si1=8U;
si0&=si1;
l20=si0;
si0=l5;
si1=80U;
si0+=si1;
l21=si0;
L233:;
{
si0=l21;
l19=si0;
sd0=l34;
sd0=fabs(sd0);
sd1=2147483648;
si0=sd0 < sd1;
si0=!(si0);
if(si0){
goto L235;
}
sd0=l34;
si0=I32_TRUNC_S_F64(sd0);
l21=si0;
goto L234;
L235:;
si0=-2147483648U;
l21=si0;
L234:;
si0=l19;
si1=l21;
si2=3440U;
si1+=si2;
si1=i32_load8_u(i->m0,(U64)si1);
si2=l22;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
sd0=l34;
si1=l21;
sd1=(F64)(I32)(si1);
sd0-=sd1;
sd1=16;
sd0*=sd1;
l34=sd0;
si0=l19;
si1=1U;
si0+=si1;
l21=si0;
si1=l5;
si2=80U;
si1+=si2;
si0-=si1;
si1=1U;
si0=si0 != si1;
if(si0){
goto L236;
}
si0=l20;
if(si0){
goto L237;
}
si0=l24;
si1=0U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L237;
}
sd0=l34;
sd1=0;
si0=sd0 == sd1;
if(si0){
goto L236;
}
L237:;
si0=l19;
si1=46U;
i32_store8(i->m0,(U64)si0+1U,si1);
si0=l19;
si1=2U;
si0+=si1;
l21=si0;
L236:;
sd0=l34;
sd1=0;
si0=sd0 != sd1;
if(si0){
goto L233;
}
}
si0=2147483645U;
si1=l7;
si2=l27;
si1-=si2;
l25=si1;
si2=l29;
si1+=si2;
l19=si1;
si0-=si1;
si1=l24;
si0=(U32)((I32)si0<(I32)si1);
if(si0){
goto L3;
}
si0=l24;
si1=2U;
si0+=si1;
si1=l21;
si2=l5;
si3=80U;
si2+=si3;
si1-=si2;
l21=si1;
si2=l21;
si3=-2U;
si2+=si3;
si3=l24;
si2=(U32)((I32)si2<(I32)si3);
si0=si2?si0:si1;
si1=l21;
si2=l24;
si0=si2?si0:si1;
l20=si0;
si1=l19;
si0+=si1;
l28=si0;
si0=l30;
si1=73728U;
si0&=si1;
l22=si0;
if(si0){
goto L238;
}
si0=l26;
si1=l28;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L238;
}
si0=l5;
si1=624U;
si0+=si1;
si1=32U;
si2=l26;
si3=l28;
si2-=si3;
l19=si2;
si3=256U;
si4=l19;
si5=256U;
si4=si4 < si5;
l24=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l24;
if(si0){
goto L239;
}
L240:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L241;
}
si0=l5;
si1=624U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L241:;
si0=l19;
si1=-256U;
si0+=si1;
l19=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L240;
}
}
L239:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L238;
}
si0=l5;
si1=624U;
si0+=si1;
si1=l19;
si2=l0;
si0=f34(i,si0,si1,si2);
L238:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L242;
}
si0=l23;
si1=l29;
si2=l0;
si0=f34(i,si0,si1,si2);
L242:;
si0=l22;
si1=65536U;
si0=si0 != si1;
if(si0){
goto L243;
}
si0=l26;
si1=l28;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L243;
}
si0=l5;
si1=624U;
si0+=si1;
si1=48U;
si2=l26;
si3=l28;
si2-=si3;
l19=si2;
si3=256U;
si4=l19;
si5=256U;
si4=si4 < si5;
l24=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l24;
if(si0){
goto L244;
}
L245:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L246;
}
si0=l5;
si1=624U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L246:;
si0=l19;
si1=-256U;
si0+=si1;
l19=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L245;
}
}
L244:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L243;
}
si0=l5;
si1=624U;
si0+=si1;
si1=l19;
si2=l0;
si0=f34(i,si0,si1,si2);
L243:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L247;
}
si0=l5;
si1=80U;
si0+=si1;
si1=l21;
si2=l0;
si0=f34(i,si0,si1,si2);
L247:;
si0=l20;
si1=l21;
si0-=si1;
l19=si0;
si1=1U;
si0=(U32)((I32)si0<(I32)si1);
if(si0){
goto L248;
}
si0=l5;
si1=624U;
si0+=si1;
si1=48U;
si2=l19;
si3=256U;
si4=l19;
si5=256U;
si4=si4 < si5;
l21=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l21;
if(si0){
goto L249;
}
L250:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L251;
}
si0=l5;
si1=624U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L251:;
si0=l19;
si1=-256U;
si0+=si1;
l19=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L250;
}
}
L249:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L248;
}
si0=l5;
si1=624U;
si0+=si1;
si1=l19;
si2=l0;
si0=f34(i,si0,si1,si2);
L248:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L252;
}
si0=l27;
si1=l25;
si2=l0;
si0=f34(i,si0,si1,si2);
L252:;
si0=l22;
si1=8192U;
si0=si0 != si1;
if(si0){
goto L5;
}
si0=l26;
si1=l28;
si0=(U32)((I32)si0<=(I32)si1);
if(si0){
goto L5;
}
si0=l5;
si1=624U;
si0+=si1;
si1=32U;
si2=l26;
si3=l28;
si2-=si3;
l19=si2;
si3=256U;
si4=l19;
si5=256U;
si4=si4 < si5;
l21=si4;
si2=si4?si2:si3;
si0=f50(i,si0,si1,si2);
si0=l21;
if(si0){
goto L253;
}
L254:;
{
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L255;
}
si0=l5;
si1=624U;
si0+=si1;
si1=256U;
si2=l0;
si0=f34(i,si0,si1,si2);
L255:;
si0=l19;
si1=-256U;
si0+=si1;
l19=si0;
si1=255U;
si0=si0 > si1;
if(si0){
goto L254;
}
}
L253:;
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=32U;
si0&=si1;
if(si0){
goto L5;
}
si0=l5;
si1=624U;
si0+=si1;
si1=l19;
si2=l0;
si0=f34(i,si0,si1,si2);
L5:;
si0=l28;
si1=l26;
si2=l28;
si3=l26;
si2=(U32)((I32)si2>(I32)si3);
si0=si2?si0:si1;
l19=si0;
si1=0U;
si0=(U32)((I32)si0>=(I32)si1);
if(si0){
goto L4;
}
}
L3:;
si0=3700U;
si1=61U;
i32_store(i->m0,(U64)si0,si1);
L2:;
si0=-1U;
l18=si0;
L1:;
si0=l5;
si1=880U;
si0+=si1;
i->g0=si0;
si0=l18;
L0:;
return si0;
}

U32 f40(exampleInstance*i,U32 l0,U32 l1) {
U32 si0,si1,si2;
si0=l0;
if(si0){
goto L1;
}
si0=0U;
goto L0;
L1:;
si0=l0;
si1=l1;
si2=0U;
si0=f39(i,si0,si1,si2);
L0:;
return si0;
}

U32 f23(exampleInstance*i,U32 l0) {
U32 si0,si1;
f22(i);
si0=l0;
si0=f14(i,si0);
l0=si0;
if(si0){
goto L1;
}
si0=0U;
goto L0;
L1:;
si0=0U;
si1=l0;
i32_store(i->m0,(U64)si0+3700U,si1);
si0=-1U;
L0:;
return si0;
}

U32 f52(exampleInstance*i,U32 l0,U32 l1,U32 l2) {
U32 l3=0;
U32 l4=0;
U32 l5=0;
U32 si0,si1,si2;
si0=l2;
si1=0U;
si0=si0 != si1;
l3=si0;
si0=l0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L4;
}
si0=l2;
si0=!(si0);
if(si0){
goto L4;
}
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=l1;
si2=255U;
si1&=si2;
si0=si0 != si1;
if(si0){
goto L5;
}
si0=l0;
l4=si0;
si0=l2;
l5=si0;
goto L2;
L5:;
si0=l2;
si1=-1U;
si0+=si1;
l5=si0;
si1=0U;
si0=si0 != si1;
l3=si0;
si0=l0;
si1=1U;
si0+=si1;
l4=si0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L3;
}
si0=l5;
si0=!(si0);
if(si0){
goto L3;
}
si0=l4;
si0=i32_load8_u(i->m0,(U64)si0);
si1=l1;
si2=255U;
si1&=si2;
si0=si0 == si1;
if(si0){
goto L2;
}
si0=l2;
si1=-2U;
si0+=si1;
l5=si0;
si1=0U;
si0=si0 != si1;
l3=si0;
si0=l0;
si1=2U;
si0+=si1;
l4=si0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L3;
}
si0=l5;
si0=!(si0);
if(si0){
goto L3;
}
si0=l4;
si0=i32_load8_u(i->m0,(U64)si0);
si1=l1;
si2=255U;
si1&=si2;
si0=si0 == si1;
if(si0){
goto L2;
}
si0=l2;
si1=-3U;
si0+=si1;
l5=si0;
si1=0U;
si0=si0 != si1;
l3=si0;
si0=l0;
si1=3U;
si0+=si1;
l4=si0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L3;
}
si0=l5;
si0=!(si0);
if(si0){
goto L3;
}
si0=l4;
si0=i32_load8_u(i->m0,(U64)si0);
si1=l1;
si2=255U;
si1&=si2;
si0=si0 == si1;
if(si0){
goto L2;
}
si0=l0;
si1=4U;
si0+=si1;
l4=si0;
si0=l2;
si1=-4U;
si0+=si1;
l5=si0;
si1=0U;
si0=si0 != si1;
l3=si0;
goto L3;
L4:;
si0=l2;
l5=si0;
si0=l0;
l4=si0;
L3:;
si0=l3;
si0=!(si0);
if(si0){
goto L1;
}
si0=l4;
si0=i32_load8_u(i->m0,(U64)si0);
si1=l1;
si2=255U;
si1&=si2;
si0=si0 == si1;
if(si0){
goto L6;
}
si0=l5;
si1=4U;
si0=si0 < si1;
if(si0){
goto L6;
}
si0=l1;
si1=255U;
si0&=si1;
si1=16843009U;
si0*=si1;
l0=si0;
L7:;
{
si0=l4;
si0=i32_load(i->m0,(U64)si0);
si1=l0;
si0^=si1;
l2=si0;
si1=-1U;
si0^=si1;
si1=l2;
si2=-16843009U;
si1+=si2;
si0&=si1;
si1=-2139062144U;
si0&=si1;
if(si0){
goto L2;
}
si0=l4;
si1=4U;
si0+=si1;
l4=si0;
si0=l5;
si1=-4U;
si0+=si1;
l5=si0;
si1=3U;
si0=si0 > si1;
if(si0){
goto L7;
}
}
L6:;
si0=l5;
si0=!(si0);
if(si0){
goto L1;
}
L2:;
si0=l1;
si1=255U;
si0&=si1;
l2=si0;
L8:;
{
si0=l4;
si0=i32_load8_u(i->m0,(U64)si0);
si1=l2;
si0=si0 != si1;
if(si0){
goto L9;
}
si0=l4;
goto L0;
L9:;
si0=l4;
si1=1U;
si0+=si1;
l4=si0;
si0=l5;
si1=-1U;
si0+=si1;
l5=si0;
if(si0){
goto L8;
}
}
L1:;
si0=0U;
L0:;
return si0;
}

U32 f24(exampleInstance*i,U32 l0) {
U32 si0;
si0=l0;
si0=i32_load(i->m0,(U64)si0+56U);
si0=f23(i,si0);
L0:;
return si0;
}

U32 f15(exampleInstance*i,U32 l0,U32 l1) {
U32 si0,si1;
si0=l0;
si1=l1;
si0=wasi_snapshot_preview1__fd_fdstat_get(i,si0,si1);
si1=65535U;
si0&=si1;
L0:;
return si0;
}

U32 f25(exampleInstance*i,U32 l0,U32 l1,U32 l2) {
U32 l3=0;
U32 l4=0;
U32 si0,si1,si2,si3,si4;
si0=i->g0;
si1=16U;
si0-=si1;
l3=si0;
i->g0=si0;
si0=-1U;
l4=si0;
si0=l2;
si1=-1U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L2;
}
si0=0U;
si1=28U;
i32_store(i->m0,(U64)si0+3700U,si1);
goto L1;
L2:;
si0=l0;
si1=l1;
si2=l2;
si3=l3;
si4=12U;
si3+=si4;
si0=f17(i,si0,si1,si2,si3);
l2=si0;
si0=!(si0);
if(si0){
goto L3;
}
si0=0U;
si1=l2;
i32_store(i->m0,(U64)si0+3700U,si1);
si0=-1U;
l4=si0;
goto L1;
L3:;
si0=l3;
si0=i32_load(i->m0,(U64)si0+12U);
l4=si0;
L1:;
si0=l3;
si1=16U;
si0+=si1;
i->g0=si0;
si0=l4;
L0:;
return si0;
}

U32 f49(exampleInstance*i,U32 l0,U32 l1,U32 l2) {
U32 l3=0;
U32 l4=0;
U32 l5=0;
U32 l6=0;
U32 si0,si1,si2,si3;
U64 sj1;
si0=l2;
si1=32U;
si0=si0 > si1;
if(si0){
goto L3;
}
si0=l1;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L2;
}
si0=l2;
si0=!(si0);
if(si0){
goto L2;
}
si0=l0;
si1=l1;
si1=i32_load8_u(i->m0,(U64)si1);
i32_store8(i->m0,(U64)si0,si1);
si0=l2;
si1=-1U;
si0+=si1;
l3=si0;
si0=l0;
si1=1U;
si0+=si1;
l4=si0;
si0=l1;
si1=1U;
si0+=si1;
l5=si0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L1;
}
si0=l3;
si0=!(si0);
if(si0){
goto L1;
}
si0=l0;
si1=l1;
si1=i32_load8_u(i->m0,(U64)si1+1U);
i32_store8(i->m0,(U64)si0+1U,si1);
si0=l2;
si1=-2U;
si0+=si1;
l3=si0;
si0=l0;
si1=2U;
si0+=si1;
l4=si0;
si0=l1;
si1=2U;
si0+=si1;
l5=si0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L1;
}
si0=l3;
si0=!(si0);
if(si0){
goto L1;
}
si0=l0;
si1=l1;
si1=i32_load8_u(i->m0,(U64)si1+2U);
i32_store8(i->m0,(U64)si0+2U,si1);
si0=l2;
si1=-3U;
si0+=si1;
l3=si0;
si0=l0;
si1=3U;
si0+=si1;
l4=si0;
si0=l1;
si1=3U;
si0+=si1;
l5=si0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L1;
}
si0=l3;
si0=!(si0);
if(si0){
goto L1;
}
si0=l0;
si1=l1;
si1=i32_load8_u(i->m0,(U64)si1+3U);
i32_store8(i->m0,(U64)si0+3U,si1);
si0=l2;
si1=-4U;
si0+=si1;
l3=si0;
si0=l0;
si1=4U;
si0+=si1;
l4=si0;
si0=l1;
si1=4U;
si0+=si1;
l5=si0;
goto L1;
L3:;
si0=l0;
si1=l1;
si2=l2;
wasmMemoryCopy(i->m0,i->m0,si0,si1,si2);
si0=l0;
goto L0;
L2:;
si0=l2;
l3=si0;
si0=l0;
l4=si0;
si0=l1;
l5=si0;
L1:;
si0=l4;
si1=3U;
si0&=si1;
l2=si0;
if(si0){
goto L5;
}
si0=l3;
si1=16U;
si0=si0 >= si1;
if(si0){
goto L7;
}
si0=l3;
l2=si0;
goto L6;
L7:;
si0=l3;
si1=-16U;
si0+=si1;
l2=si0;
si1=16U;
si0&=si1;
if(si0){
goto L8;
}
si0=l4;
si1=l5;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
si0=l4;
si1=l5;
sj1=i64_load(i->m0,(U64)si1+8U);
i64_store(i->m0,(U64)si0+8U,sj1);
si0=l4;
si1=16U;
si0+=si1;
l4=si0;
si0=l5;
si1=16U;
si0+=si1;
l5=si0;
si0=l2;
l3=si0;
L8:;
si0=l2;
si1=16U;
si0=si0 < si1;
if(si0){
goto L6;
}
si0=l3;
l2=si0;
L9:;
{
si0=l4;
si1=l5;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
si0=l4;
si1=l5;
sj1=i64_load(i->m0,(U64)si1+8U);
i64_store(i->m0,(U64)si0+8U,sj1);
si0=l4;
si1=l5;
sj1=i64_load(i->m0,(U64)si1+16U);
i64_store(i->m0,(U64)si0+16U,sj1);
si0=l4;
si1=l5;
sj1=i64_load(i->m0,(U64)si1+24U);
i64_store(i->m0,(U64)si0+24U,sj1);
si0=l4;
si1=32U;
si0+=si1;
l4=si0;
si0=l5;
si1=32U;
si0+=si1;
l5=si0;
si0=l2;
si1=-32U;
si0+=si1;
l2=si0;
si1=15U;
si0=si0 > si1;
if(si0){
goto L9;
}
}
L6:;
si0=l2;
si1=8U;
si0=si0 < si1;
if(si0){
goto L10;
}
si0=l4;
si1=l5;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
si0=l5;
si1=8U;
si0+=si1;
l5=si0;
si0=l4;
si1=8U;
si0+=si1;
l4=si0;
L10:;
si0=l2;
si1=4U;
si0&=si1;
si0=!(si0);
if(si0){
goto L11;
}
si0=l4;
si1=l5;
si1=i32_load(i->m0,(U64)si1);
i32_store(i->m0,(U64)si0,si1);
si0=l5;
si1=4U;
si0+=si1;
l5=si0;
si0=l4;
si1=4U;
si0+=si1;
l4=si0;
L11:;
si0=l2;
si1=2U;
si0&=si1;
si0=!(si0);
if(si0){
goto L12;
}
si0=l4;
si1=l5;
si1=i32_load16_u(i->m0,(U64)si1);
i32_store16(i->m0,(U64)si0,si1);
si0=l4;
si1=2U;
si0+=si1;
l4=si0;
si0=l5;
si1=2U;
si0+=si1;
l5=si0;
L12:;
si0=l2;
si1=1U;
si0&=si1;
si0=!(si0);
if(si0){
goto L4;
}
si0=l4;
si1=l5;
si1=i32_load8_u(i->m0,(U64)si1);
i32_store8(i->m0,(U64)si0,si1);
si0=l0;
goto L0;
L5:;
si0=l3;
si1=32U;
si0=si0 < si1;
if(si0){
goto L17;
}
si0=l4;
si1=l5;
si1=i32_load(i->m0,(U64)si1);
l3=si1;
i32_store8(i->m0,(U64)si0,si1);
si0=l2;
si1=-1U;
si0+=si1;
switch(si0){
case 0:
goto L16;
case 1:
goto L19;
case 2:
goto L18;
default:
goto L16;
}
L19:;
si0=l4;
si1=l3;
si2=8U;
si1>>=(si2&31);
i32_store8(i->m0,(U64)si0+1U,si1);
si0=l4;
si1=l5;
si2=6U;
si1+=si2;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0+6U,sj1);
si0=l4;
si1=l5;
si1=i32_load(i->m0,(U64)si1+4U);
si2=16U;
si1<<=(si2&31);
si2=l3;
si3=16U;
si2>>=(si3&31);
si1|=si2;
i32_store(i->m0,(U64)si0+2U,si1);
si0=l4;
si1=18U;
si0+=si1;
l2=si0;
si0=l5;
si1=18U;
si0+=si1;
l1=si0;
si0=14U;
l6=si0;
si0=l5;
si1=14U;
si0+=si1;
si0=i32_load(i->m0,(U64)si0);
l5=si0;
si0=14U;
l3=si0;
goto L15;
L18:;
si0=l4;
si1=l5;
si2=5U;
si1+=si2;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0+5U,sj1);
si0=l4;
si1=l5;
si1=i32_load(i->m0,(U64)si1+4U);
si2=24U;
si1<<=(si2&31);
si2=l3;
si3=8U;
si2>>=(si3&31);
si1|=si2;
i32_store(i->m0,(U64)si0+1U,si1);
si0=l4;
si1=17U;
si0+=si1;
l2=si0;
si0=l5;
si1=17U;
si0+=si1;
l1=si0;
si0=13U;
l6=si0;
si0=l5;
si1=13U;
si0+=si1;
si0=i32_load(i->m0,(U64)si0);
l5=si0;
si0=15U;
l3=si0;
goto L15;
L17:;
si0=l3;
si1=16U;
si0=si0 >= si1;
if(si0){
goto L21;
}
si0=l4;
l2=si0;
si0=l5;
l1=si0;
goto L20;
L21:;
si0=l4;
si1=l5;
si1=i32_load8_u(i->m0,(U64)si1);
i32_store8(i->m0,(U64)si0,si1);
si0=l4;
si1=l5;
si1=i32_load(i->m0,(U64)si1+1U);
i32_store(i->m0,(U64)si0+1U,si1);
si0=l4;
si1=l5;
sj1=i64_load(i->m0,(U64)si1+5U);
i64_store(i->m0,(U64)si0+5U,sj1);
si0=l4;
si1=l5;
si1=i32_load16_u(i->m0,(U64)si1+13U);
i32_store16(i->m0,(U64)si0+13U,si1);
si0=l4;
si1=l5;
si1=i32_load8_u(i->m0,(U64)si1+15U);
i32_store8(i->m0,(U64)si0+15U,si1);
si0=l4;
si1=16U;
si0+=si1;
l2=si0;
si0=l5;
si1=16U;
si0+=si1;
l1=si0;
L20:;
si0=l3;
si1=8U;
si0&=si1;
if(si0){
goto L14;
}
goto L13;
L16:;
si0=l4;
si1=l3;
si2=16U;
si1>>=(si2&31);
i32_store8(i->m0,(U64)si0+2U,si1);
si0=l4;
si1=l3;
si2=8U;
si1>>=(si2&31);
i32_store8(i->m0,(U64)si0+1U,si1);
si0=l4;
si1=l5;
si2=7U;
si1+=si2;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0+7U,sj1);
si0=l4;
si1=l5;
si1=i32_load(i->m0,(U64)si1+4U);
si2=8U;
si1<<=(si2&31);
si2=l3;
si3=24U;
si2>>=(si3&31);
si1|=si2;
i32_store(i->m0,(U64)si0+3U,si1);
si0=l4;
si1=19U;
si0+=si1;
l2=si0;
si0=l5;
si1=19U;
si0+=si1;
l1=si0;
si0=15U;
l6=si0;
si0=l5;
si1=15U;
si0+=si1;
si0=i32_load(i->m0,(U64)si0);
l5=si0;
si0=13U;
l3=si0;
L15:;
si0=l4;
si1=l6;
si0+=si1;
si1=l5;
i32_store(i->m0,(U64)si0,si1);
L14:;
si0=l2;
si1=l1;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
si0=l2;
si1=8U;
si0+=si1;
l2=si0;
si0=l1;
si1=8U;
si0+=si1;
l1=si0;
L13:;
si0=l3;
si1=4U;
si0&=si1;
si0=!(si0);
if(si0){
goto L22;
}
si0=l2;
si1=l1;
si1=i32_load(i->m0,(U64)si1);
i32_store(i->m0,(U64)si0,si1);
si0=l2;
si1=4U;
si0+=si1;
l2=si0;
si0=l1;
si1=4U;
si0+=si1;
l1=si0;
L22:;
si0=l3;
si1=2U;
si0&=si1;
si0=!(si0);
if(si0){
goto L23;
}
si0=l2;
si1=l1;
si1=i32_load16_u(i->m0,(U64)si1);
i32_store16(i->m0,(U64)si0,si1);
si0=l2;
si1=2U;
si0+=si1;
l2=si0;
si0=l1;
si1=2U;
si0+=si1;
l1=si0;
L23:;
si0=l3;
si1=1U;
si0&=si1;
si0=!(si0);
if(si0){
goto L4;
}
si0=l2;
si1=l1;
si1=i32_load8_u(i->m0,(U64)si1);
i32_store8(i->m0,(U64)si0,si1);
L4:;
si0=l0;
L0:;
return si0;
}

void f46(exampleInstance*i,U32 l0,U32 l1,U32 l2) {
U32 si0,si1,si2;
U64 sj1;
F64 sd1;
si0=l1;
si1=-9U;
si0+=si1;
switch(si0){
case 0:
goto L2;
case 1:
goto L19;
case 2:
goto L18;
case 3:
goto L15;
case 4:
goto L17;
case 5:
goto L16;
case 6:
goto L14;
case 7:
goto L13;
case 8:
goto L12;
case 9:
goto L11;
case 10:
goto L10;
case 11:
goto L9;
case 12:
goto L8;
case 13:
goto L7;
case 14:
goto L6;
case 15:
goto L5;
case 16:
goto L4;
case 17:
goto L3;
default:
goto L1;
}
L19:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load32_s(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L18:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load32_u(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L17:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load32_s(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L16:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load32_u(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L15:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
si2=7U;
si1+=si2;
si2=-8U;
si1&=si2;
l1=si1;
si2=8U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L14:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load16_s(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L13:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load16_u(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L12:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load8_s(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L11:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load8_u(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L10:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
si2=7U;
si1+=si2;
si2=-8U;
si1&=si2;
l1=si1;
si2=8U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L9:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load32_u(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L8:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
si2=7U;
si1+=si2;
si2=-8U;
si1&=si2;
l1=si1;
si2=8U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L7:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
si2=7U;
si1+=si2;
si2=-8U;
si1&=si2;
l1=si1;
si2=8U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L6:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load32_s(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L5:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sj1=i64_load32_u(i->m0,(U64)si1);
i64_store(i->m0,(U64)si0,sj1);
goto L0;
L4:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
si2=7U;
si1+=si2;
si2=-8U;
si1&=si2;
l1=si1;
si2=8U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
sd1=f64_load(i->m0,(U64)si1);
f64_store(i->m0,(U64)si0,sd1);
goto L0;
L3:;
f48(i);
UNREACHABLE;
L2:;
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1);
l1=si1;
si2=4U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
si1=i32_load(i->m0,(U64)si1);
i32_store(i->m0,(U64)si0,si1);
L1:;
L0:;
}

U32 f42(exampleInstance*i,U32 l0,U32 l1) {
U32 l2=0;
U32 si0,si1,si2,si3,si4,si5,si6;
si0=l0;
si0=f51(i,si0);
l2=si0;
si0=-1U;
si1=0U;
si2=l2;
si3=l0;
si4=1U;
si5=l2;
si6=l1;
si3=f35(i,si3,si4,si5,si6);
si2=si2 != si3;
si0=si2?si0:si1;
L0:;
return si0;
}

U32 f26(exampleInstance*i,U32 l0,U32 l1,U32 l2) {
U32 l3=0;
U32 l4=0;
U32 l5=0;
U32 l6=0;
U32 l7=0;
U32 l8=0;
U32 l9=0;
U32 si0,si1,si2,si3,si4,si5;
U64 sj1;
si0=i->g0;
si1=16U;
si0-=si1;
l3=si0;
i->g0=si0;
si0=l3;
si1=l2;
i32_store(i->m0,(U64)si0+12U,si1);
si0=l3;
si1=l1;
i32_store(i->m0,(U64)si0+8U,si1);
si0=l3;
si1=l0;
si1=i32_load(i->m0,(U64)si1+24U);
l1=si1;
i32_store(i->m0,(U64)si0,si1);
si0=l3;
si1=l0;
si1=i32_load(i->m0,(U64)si1+20U);
si2=l1;
si1-=si2;
l4=si1;
i32_store(i->m0,(U64)si0+4U,si1);
si0=2U;
l5=si0;
si0=l0;
si0=i32_load(i->m0,(U64)si0+56U);
si1=l3;
si2=2U;
si0=f25(i,si0,si1,si2);
l1=si0;
si1=l4;
si2=l2;
si1+=si2;
l6=si1;
si0=si0 == si1;
if(si0){
goto L2;
}
si0=l3;
l4=si0;
L3:;
{
si0=l1;
si1=-1U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L4;
}
si0=0U;
l1=si0;
si0=l0;
si1=0U;
i32_store(i->m0,(U64)si0+24U,si1);
si0=l0;
sj1=0ULL;
i64_store(i->m0,(U64)si0+16U,sj1);
si0=l0;
si1=l0;
si1=i32_load(i->m0,(U64)si1);
si2=32U;
si1|=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l5;
si1=2U;
si0=si0 == si1;
if(si0){
goto L1;
}
si0=l2;
si1=l4;
si1=i32_load(i->m0,(U64)si1+4U);
si0-=si1;
l1=si0;
goto L1;
L4:;
si0=l4;
si1=l1;
si2=l4;
si2=i32_load(i->m0,(U64)si2+4U);
l7=si2;
si1=si1 > si2;
l8=si1;
si2=3U;
si1<<=(si2&31);
si0+=si1;
l9=si0;
si1=l9;
si1=i32_load(i->m0,(U64)si1);
si2=l1;
si3=l7;
si4=0U;
si5=l8;
si3=si5?si3:si4;
si2-=si3;
l7=si2;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l4;
si1=12U;
si2=4U;
si3=l8;
si1=si3?si1:si2;
si0+=si1;
l4=si0;
si1=l4;
si1=i32_load(i->m0,(U64)si1);
si2=l7;
si1-=si2;
i32_store(i->m0,(U64)si0,si1);
si0=l9;
l4=si0;
si0=l6;
si1=l1;
si0-=si1;
l6=si0;
si1=l0;
si1=i32_load(i->m0,(U64)si1+56U);
si2=l9;
si3=l5;
si4=l8;
si3-=si4;
l5=si3;
si1=f25(i,si1,si2,si3);
l1=si1;
si0=si0 != si1;
if(si0){
goto L3;
}
}
L2:;
si0=l0;
si1=l0;
si1=i32_load(i->m0,(U64)si1+40U);
l1=si1;
i32_store(i->m0,(U64)si0+24U,si1);
si0=l0;
si1=l1;
i32_store(i->m0,(U64)si0+20U,si1);
si0=l0;
si1=l1;
si2=l0;
si2=i32_load(i->m0,(U64)si2+44U);
si1+=si2;
i32_store(i->m0,(U64)si0+16U,si1);
si0=l2;
l1=si0;
L1:;
si0=l3;
si1=16U;
si0+=si1;
i->g0=si0;
si0=l1;
L0:;
return si0;
}

U32 f16(exampleInstance*i,U32 l0,U64 l1,U32 l2,U32 l3) {
U32 si0,si1,si2,si3;
U64 sj1;
si0=l0;
sj1=l1;
si2=l2;
si3=l3;
si0=wasi_snapshot_preview1__fd_seek(i,si0,sj1,si2,si3);
si1=65535U;
si0&=si1;
L0:;
return si0;
}

U32 f36(exampleInstance*i,U32 l0,U32 l1) {
U32 si0;
si0=l0;
L0:;
return si0;
}

void f43(exampleInstance*i) {
UNREACHABLE;
L0:;
}

U32 f28(exampleInstance*i,U32 l0,U32 l1,U32 l2) {
U32 si0,si1,si2;
si0=l0;
si1=1U;
i32_store(i->m0,(U64)si0+32U,si1);
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
si1=64U;
si0&=si1;
if(si0){
goto L1;
}
si0=l0;
si0=i32_load(i->m0,(U64)si0+56U);
si0=f27(i,si0);
if(si0){
goto L1;
}
si0=l0;
si1=-1U;
i32_store(i->m0,(U64)si0+64U,si1);
L1:;
si0=l0;
si1=l1;
si2=l2;
si0=f26(i,si0,si1,si2);
L0:;
return si0;
}

U32 f34(exampleInstance*i,U32 l0,U32 l1,U32 l2) {
U32 l3=0;
U32 l4=0;
U32 l5=0;
U32 l6=0;
U32 si0,si1,si2,si3;
si0=l2;
si0=i32_load(i->m0,(U64)si0+16U);
l3=si0;
if(si0){
goto L2;
}
si0=0U;
l4=si0;
si0=l2;
si0=f33(i,si0);
if(si0){
goto L1;
}
si0=l2;
si0=i32_load(i->m0,(U64)si0+16U);
l3=si0;
L2:;
si0=l3;
si1=l2;
si1=i32_load(i->m0,(U64)si1+20U);
l5=si1;
si0-=si1;
si1=l1;
si0=si0 >= si1;
if(si0){
goto L3;
}
si0=l2;
si1=l0;
si2=l1;
si3=l2;
si3=i32_load(i->m0,(U64)si3+32U);
si0=TF(i->t0,si3,U32 (*)(exampleInstance*,U32,U32,U32))(i,si0,si1,si2);
goto L0;
L3:;
si0=0U;
l6=si0;
si0=l2;
si0=i32_load(i->m0,(U64)si0+64U);
si1=0U;
si0=(U32)((I32)si0<(I32)si1);
if(si0){
goto L4;
}
si0=l1;
si0=!(si0);
if(si0){
goto L4;
}
si0=l0;
si1=l1;
si0+=si1;
l4=si0;
si0=0U;
l3=si0;
L6:;
{
si0=l4;
si1=l3;
si0+=si1;
si1=-1U;
si0+=si1;
si0=i32_load8_u(i->m0,(U64)si0);
si1=10U;
si0=si0 == si1;
if(si0){
goto L5;
}
si0=l1;
si1=l3;
si2=-1U;
si1+=si2;
l3=si1;
si0+=si1;
if(si0){
goto L6;
}
}
si0=0U;
l6=si0;
goto L4;
L5:;
si0=l2;
si1=l0;
si2=l1;
si3=l3;
si2+=si3;
l6=si2;
si3=l2;
si3=i32_load(i->m0,(U64)si3+32U);
si0=TF(i->t0,si3,U32 (*)(exampleInstance*,U32,U32,U32))(i,si0,si1,si2);
l4=si0;
si1=l6;
si0=si0 < si1;
if(si0){
goto L1;
}
si0=l6;
si1=l0;
si0+=si1;
l0=si0;
si0=0U;
si1=l3;
si0-=si1;
l1=si0;
si0=l2;
si0=i32_load(i->m0,(U64)si0+20U);
l5=si0;
L4:;
si0=l5;
si1=l0;
si2=l1;
si0=f49(i,si0,si1,si2);
si0=l2;
si1=l2;
si1=i32_load(i->m0,(U64)si1+20U);
si2=l1;
si1+=si2;
i32_store(i->m0,(U64)si0+20U,si1);
si0=l6;
si1=l1;
si0+=si1;
l4=si0;
L1:;
si0=l4;
L0:;
return si0;
}

U32 f50(exampleInstance*i,U32 l0,U32 l1,U32 l2) {
U32 l3=0;
U32 l4=0;
U32 l5=0;
U64 l6=0;
U32 si0,si1,si2;
U64 sj0,sj1;
si0=l2;
si1=33U;
si0=si0 < si1;
if(si0){
goto L1;
}
si0=l0;
si1=l1;
si2=l2;
wasmMemoryFill(i->m0,si0,si1,si2);
si0=l0;
goto L0;
L1:;
si0=l2;
si0=!(si0);
if(si0){
goto L2;
}
si0=l0;
si1=l1;
i32_store8(i->m0,(U64)si0,si1);
si0=l0;
si1=l2;
si0+=si1;
l3=si0;
si1=-1U;
si0+=si1;
si1=l1;
i32_store8(i->m0,(U64)si0,si1);
si0=l2;
si1=3U;
si0=si0 < si1;
if(si0){
goto L2;
}
si0=l0;
si1=l1;
i32_store8(i->m0,(U64)si0+2U,si1);
si0=l0;
si1=l1;
i32_store8(i->m0,(U64)si0+1U,si1);
si0=l3;
si1=-3U;
si0+=si1;
si1=l1;
i32_store8(i->m0,(U64)si0,si1);
si0=l3;
si1=-2U;
si0+=si1;
si1=l1;
i32_store8(i->m0,(U64)si0,si1);
si0=l2;
si1=7U;
si0=si0 < si1;
if(si0){
goto L2;
}
si0=l0;
si1=l1;
i32_store8(i->m0,(U64)si0+3U,si1);
si0=l3;
si1=-4U;
si0+=si1;
si1=l1;
i32_store8(i->m0,(U64)si0,si1);
si0=l2;
si1=9U;
si0=si0 < si1;
if(si0){
goto L2;
}
si0=l0;
si1=0U;
si2=l0;
si1-=si2;
si2=3U;
si1&=si2;
l4=si1;
si0+=si1;
l5=si0;
si1=l1;
si2=255U;
si1&=si2;
si2=16843009U;
si1*=si2;
l3=si1;
i32_store(i->m0,(U64)si0,si1);
si0=l5;
si1=l2;
si2=l4;
si1-=si2;
si2=-4U;
si1&=si2;
l1=si1;
si0+=si1;
l2=si0;
si1=-4U;
si0+=si1;
si1=l3;
i32_store(i->m0,(U64)si0,si1);
si0=l1;
si1=9U;
si0=si0 < si1;
if(si0){
goto L2;
}
si0=l5;
si1=l3;
i32_store(i->m0,(U64)si0+8U,si1);
si0=l5;
si1=l3;
i32_store(i->m0,(U64)si0+4U,si1);
si0=l2;
si1=-8U;
si0+=si1;
si1=l3;
i32_store(i->m0,(U64)si0,si1);
si0=l2;
si1=-12U;
si0+=si1;
si1=l3;
i32_store(i->m0,(U64)si0,si1);
si0=l1;
si1=25U;
si0=si0 < si1;
if(si0){
goto L2;
}
si0=l5;
si1=l3;
i32_store(i->m0,(U64)si0+24U,si1);
si0=l5;
si1=l3;
i32_store(i->m0,(U64)si0+20U,si1);
si0=l5;
si1=l3;
i32_store(i->m0,(U64)si0+16U,si1);
si0=l5;
si1=l3;
i32_store(i->m0,(U64)si0+12U,si1);
si0=l2;
si1=-16U;
si0+=si1;
si1=l3;
i32_store(i->m0,(U64)si0,si1);
si0=l2;
si1=-20U;
si0+=si1;
si1=l3;
i32_store(i->m0,(U64)si0,si1);
si0=l2;
si1=-24U;
si0+=si1;
si1=l3;
i32_store(i->m0,(U64)si0,si1);
si0=l2;
si1=-28U;
si0+=si1;
si1=l3;
i32_store(i->m0,(U64)si0,si1);
si0=l1;
si1=l5;
si2=4U;
si1&=si2;
si2=24U;
si1|=si2;
l2=si1;
si0-=si1;
l1=si0;
si1=32U;
si0=si0 < si1;
if(si0){
goto L2;
}
si0=l3;
sj0=(U64)(si0);
sj1=4294967297ULL;
sj0*=sj1;
l6=sj0;
si0=l5;
si1=l2;
si0+=si1;
l2=si0;
L3:;
{
si0=l2;
sj1=l6;
i64_store(i->m0,(U64)si0+24U,sj1);
si0=l2;
sj1=l6;
i64_store(i->m0,(U64)si0+16U,sj1);
si0=l2;
sj1=l6;
i64_store(i->m0,(U64)si0+8U,sj1);
si0=l2;
sj1=l6;
i64_store(i->m0,(U64)si0,sj1);
si0=l2;
si1=32U;
si0+=si1;
l2=si0;
si0=l1;
si1=-32U;
si0+=si1;
l1=si0;
si1=31U;
si0=si0 > si1;
if(si0){
goto L3;
}
}
L2:;
si0=l0;
L0:;
return si0;
}

void f32(exampleInstance*i) {
U32 l0=0;
U32 l1=0;
U32 l2=0;
U32 si0,si1,si2,si3;
U64 sj0,sj1;
si0=f31(i);
si0=i32_load(i->m0,(U64)si0);
l0=si0;
si0=!(si0);
if(si0){
goto L1;
}
L2:;
{
si0=l0;
si0=i32_load(i->m0,(U64)si0+20U);
si1=l0;
si1=i32_load(i->m0,(U64)si1+24U);
si0=si0 == si1;
if(si0){
goto L3;
}
si0=l0;
si1=0U;
si2=0U;
si3=l0;
si3=i32_load(i->m0,(U64)si3+32U);
si0=TF(i->t0,si3,U32 (*)(exampleInstance*,U32,U32,U32))(i,si0,si1,si2);
L3:;
si0=l0;
si0=i32_load(i->m0,(U64)si0+4U);
l1=si0;
si1=l0;
si1=i32_load(i->m0,(U64)si1+8U);
l2=si1;
si0=si0 == si1;
if(si0){
goto L4;
}
si0=l0;
si1=l1;
si2=l2;
si1-=si2;
sj1=(U64)(I64)(I32)(si1);
si2=1U;
si3=l0;
si3=i32_load(i->m0,(U64)si3+36U);
sj0=TF(i->t0,si3,U64 (*)(exampleInstance*,U32,U64,U32))(i,si0,sj1,si2);
L4:;
si0=l0;
si0=i32_load(i->m0,(U64)si0+52U);
l0=si0;
if(si0){
goto L2;
}
}
L1:;
si0=0U;
si0=i32_load(i->m0,(U64)si0+4748U);
l0=si0;
si0=!(si0);
if(si0){
goto L5;
}
si0=l0;
si0=i32_load(i->m0,(U64)si0+20U);
si1=l0;
si1=i32_load(i->m0,(U64)si1+24U);
si0=si0 == si1;
if(si0){
goto L6;
}
si0=l0;
si1=0U;
si2=0U;
si3=l0;
si3=i32_load(i->m0,(U64)si3+32U);
si0=TF(i->t0,si3,U32 (*)(exampleInstance*,U32,U32,U32))(i,si0,si1,si2);
L6:;
si0=l0;
si0=i32_load(i->m0,(U64)si0+4U);
l1=si0;
si1=l0;
si1=i32_load(i->m0,(U64)si1+8U);
l2=si1;
si0=si0 == si1;
if(si0){
goto L5;
}
si0=l0;
si1=l1;
si2=l2;
si1-=si2;
sj1=(U64)(I64)(I32)(si1);
si2=1U;
si3=l0;
si3=i32_load(i->m0,(U64)si3+36U);
sj0=TF(i->t0,si3,U64 (*)(exampleInstance*,U32,U64,U32))(i,si0,sj1,si2);
L5:;
si0=0U;
si0=i32_load(i->m0,(U64)si0+3568U);
l0=si0;
si0=!(si0);
if(si0){
goto L7;
}
si0=l0;
si0=i32_load(i->m0,(U64)si0+20U);
si1=l0;
si1=i32_load(i->m0,(U64)si1+24U);
si0=si0 == si1;
if(si0){
goto L8;
}
si0=l0;
si1=0U;
si2=0U;
si3=l0;
si3=i32_load(i->m0,(U64)si3+32U);
si0=TF(i->t0,si3,U32 (*)(exampleInstance*,U32,U32,U32))(i,si0,si1,si2);
L8:;
si0=l0;
si0=i32_load(i->m0,(U64)si0+4U);
l1=si0;
si1=l0;
si1=i32_load(i->m0,(U64)si1+8U);
l2=si1;
si0=si0 == si1;
if(si0){
goto L7;
}
si0=l0;
si1=l1;
si2=l2;
si1-=si2;
sj1=(U64)(I64)(I32)(si1);
si2=1U;
si3=l0;
si3=i32_load(i->m0,(U64)si3+36U);
sj0=TF(i->t0,si3,U64 (*)(exampleInstance*,U32,U64,U32))(i,si0,sj1,si2);
L7:;
si0=0U;
si0=i32_load(i->m0,(U64)si0+3688U);
l0=si0;
si0=!(si0);
if(si0){
goto L9;
}
si0=l0;
si0=i32_load(i->m0,(U64)si0+20U);
si1=l0;
si1=i32_load(i->m0,(U64)si1+24U);
si0=si0 == si1;
if(si0){
goto L10;
}
si0=l0;
si1=0U;
si2=0U;
si3=l0;
si3=i32_load(i->m0,(U64)si3+32U);
si0=TF(i->t0,si3,U32 (*)(exampleInstance*,U32,U32,U32))(i,si0,si1,si2);
L10:;
si0=l0;
si0=i32_load(i->m0,(U64)si0+4U);
l1=si0;
si1=l0;
si1=i32_load(i->m0,(U64)si1+8U);
l2=si1;
si0=si0 == si1;
if(si0){
goto L9;
}
si0=l0;
si1=l1;
si2=l2;
si1-=si2;
sj1=(U64)(I64)(I32)(si1);
si2=1U;
si3=l0;
si3=i32_load(i->m0,(U64)si3+36U);
sj0=TF(i->t0,si3,U64 (*)(exampleInstance*,U32,U64,U32))(i,si0,sj1,si2);
L9:;
L0:;
}

U32 f14(exampleInstance*i,U32 l0) {
U32 si0,si1;
si0=l0;
si0=wasi_snapshot_preview1__fd_close(i,si0);
si1=65535U;
si0&=si1;
L0:;
return si0;
}

U64 f29(exampleInstance*i,U32 l0,U64 l1,U32 l2) {
U32 l3=0;
U32 si0,si1,si2,si3,si4;
U64 sj0,sj1;
si0=i->g0;
si1=16U;
si0-=si1;
l3=si0;
i->g0=si0;
si0=l0;
sj1=l1;
si2=l2;
si3=255U;
si2&=si3;
si3=l3;
si4=8U;
si3+=si4;
si0=f16(i,si0,sj1,si2,si3);
l2=si0;
si0=!(si0);
if(si0){
goto L2;
}
si0=0U;
si1=70U;
si2=l2;
si3=l2;
si4=76U;
si3=si3 == si4;
si1=si3?si1:si2;
i32_store(i->m0,(U64)si0+3700U,si1);
sj0=-1ULL;
l1=sj0;
goto L1;
L2:;
si0=l3;
sj0=i64_load(i->m0,(U64)si0+8U);
l1=sj0;
L1:;
si0=l3;
si1=16U;
si0+=si1;
i->g0=si0;
sj0=l1;
L0:;
return sj0;
}

void f11(exampleInstance*i) {
L0:;
}

void f19(exampleInstance*i) {
L0:;
}

void f22(exampleInstance*i) {
L0:;
}

U32 f44(exampleInstance*i,U32 l0,U32 l1,U32 l2) {
U32 l3=0;
U32 l4=0;
U32 l5=0;
U32 si0,si1,si2,si3,si4,si5;
U64 sj1;
si0=i->g0;
si1=208U;
si0-=si1;
l3=si0;
i->g0=si0;
si0=l3;
si1=l2;
i32_store(i->m0,(U64)si0+204U,si1);
si0=l3;
si1=160U;
si0+=si1;
si1=32U;
si0+=si1;
sj1=0ULL;
i64_store(i->m0,(U64)si0,sj1);
si0=l3;
si1=184U;
si0+=si1;
sj1=0ULL;
i64_store(i->m0,(U64)si0,sj1);
si0=l3;
si1=176U;
si0+=si1;
sj1=0ULL;
i64_store(i->m0,(U64)si0,sj1);
si0=l3;
sj1=0ULL;
i64_store(i->m0,(U64)si0+168U,sj1);
si0=l3;
sj1=0ULL;
i64_store(i->m0,(U64)si0+160U,sj1);
si0=l3;
si1=l2;
i32_store(i->m0,(U64)si0+200U,si1);
si0=0U;
si1=l1;
si2=l3;
si3=200U;
si2+=si3;
si3=l3;
si4=80U;
si3+=si4;
si4=l3;
si5=160U;
si4+=si5;
si0=f45(i,si0,si1,si2,si3,si4);
si1=0U;
si0=(U32)((I32)si0>=(I32)si1);
if(si0){
goto L2;
}
si0=-1U;
l0=si0;
goto L1;
L2:;
si0=l0;
si0=i32_load(i->m0,(U64)si0);
l4=si0;
si0=l0;
si0=i32_load(i->m0,(U64)si0+60U);
si1=0U;
si0=(U32)((I32)si0>(I32)si1);
if(si0){
goto L3;
}
si0=l0;
si1=l4;
si2=-33U;
si1&=si2;
i32_store(i->m0,(U64)si0,si1);
L3:;
si0=l0;
si0=i32_load(i->m0,(U64)si0+44U);
if(si0){
goto L7;
}
si0=l0;
si1=80U;
i32_store(i->m0,(U64)si0+44U,si1);
si0=l0;
si1=0U;
i32_store(i->m0,(U64)si0+24U,si1);
si0=l0;
sj1=0ULL;
i64_store(i->m0,(U64)si0+16U,sj1);
si0=l0;
si0=i32_load(i->m0,(U64)si0+40U);
l5=si0;
si0=l0;
si1=l3;
i32_store(i->m0,(U64)si0+40U,si1);
goto L6;
L7:;
si0=0U;
l5=si0;
si0=l0;
si0=i32_load(i->m0,(U64)si0+16U);
if(si0){
goto L5;
}
L6:;
si0=-1U;
l2=si0;
si0=l0;
si0=f33(i,si0);
if(si0){
goto L4;
}
L5:;
si0=l0;
si1=l1;
si2=l3;
si3=200U;
si2+=si3;
si3=l3;
si4=80U;
si3+=si4;
si4=l3;
si5=160U;
si4+=si5;
si0=f45(i,si0,si1,si2,si3,si4);
l2=si0;
L4:;
si0=l4;
si1=32U;
si0&=si1;
l1=si0;
si0=l5;
si0=!(si0);
if(si0){
goto L8;
}
si0=l0;
si1=0U;
si2=0U;
si3=l0;
si3=i32_load(i->m0,(U64)si3+32U);
si0=TF(i->t0,si3,U32 (*)(exampleInstance*,U32,U32,U32))(i,si0,si1,si2);
si0=l0;
si1=0U;
i32_store(i->m0,(U64)si0+44U,si1);
si0=l0;
si1=l5;
i32_store(i->m0,(U64)si0+40U,si1);
si0=l0;
si1=0U;
i32_store(i->m0,(U64)si0+24U,si1);
si0=l0;
si0=i32_load(i->m0,(U64)si0+20U);
l5=si0;
si0=l0;
sj1=0ULL;
i64_store(i->m0,(U64)si0+16U,sj1);
si0=l2;
si1=-1U;
si2=l5;
si0=si2?si0:si1;
l2=si0;
L8:;
si0=l0;
si1=l0;
si1=i32_load(i->m0,(U64)si1);
l5=si1;
si2=l1;
si1|=si2;
i32_store(i->m0,(U64)si0,si1);
si0=-1U;
si1=l2;
si2=l5;
si3=32U;
si2&=si3;
si0=si2?si0:si1;
l0=si0;
L1:;
si0=l3;
si1=208U;
si0+=si1;
i->g0=si0;
si0=l0;
L0:;
return si0;
}

U32 f27(exampleInstance*i,U32 l0) {
U32 l1=0;
U32 l2=0;
U32 si0,si1,si2;
si0=i->g0;
si1=32U;
si0-=si1;
l1=si0;
i->g0=si0;
si0=l0;
si1=l1;
si2=8U;
si1+=si2;
si0=f15(i,si0,si1);
l0=si0;
if(si0){
goto L2;
}
si0=59U;
l0=si0;
si0=l1;
si0=i32_load8_u(i->m0,(U64)si0+8U);
si1=2U;
si0=si0 != si1;
if(si0){
goto L2;
}
si0=l1;
si0=i32_load8_u(i->m0,(U64)si0+16U);
si1=36U;
si0&=si1;
if(si0){
goto L2;
}
si0=1U;
l2=si0;
goto L1;
L2:;
si0=0U;
l2=si0;
si0=0U;
si1=l0;
i32_store(i->m0,(U64)si0+3700U,si1);
L1:;
si0=l1;
si1=32U;
si0+=si1;
i->g0=si0;
si0=l2;
L0:;
return si0;
}

void f48(exampleInstance*i) {
U32 si0,si1;
si0=1118U;
si1=3576U;
si0=f42(i,si0,si1);
f43(i);
UNREACHABLE;
L0:;
}

U32 f39(exampleInstance*i,U32 l0,U32 l1,U32 l2) {
U32 l3=0;
U32 si0,si1,si2;
si0=1U;
l3=si0;
si0=l0;
si0=!(si0);
if(si0){
goto L1;
}
si0=l1;
si1=127U;
si0=si0 > si1;
if(si0){
goto L2;
}
si0=l0;
si1=l1;
i32_store8(i->m0,(U64)si0,si1);
si0=1U;
goto L0;
L2:;
si0=0U;
si0=i32_load(i->m0,(U64)si0+4752U);
if(si0){
goto L4;
}
si0=l1;
si1=-128U;
si0&=si1;
si1=57216U;
si0=si0 == si1;
if(si0){
goto L5;
}
si0=0U;
si1=25U;
i32_store(i->m0,(U64)si0+3700U,si1);
goto L3;
L5:;
si0=l0;
si1=l1;
i32_store8(i->m0,(U64)si0,si1);
si0=1U;
goto L0;
L4:;
si0=l1;
si1=2047U;
si0=si0 > si1;
if(si0){
goto L6;
}
si0=l0;
si1=l1;
si2=63U;
si1&=si2;
si2=128U;
si1|=si2;
i32_store8(i->m0,(U64)si0+1U,si1);
si0=l0;
si1=l1;
si2=6U;
si1>>=(si2&31);
si2=192U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
si0=2U;
goto L0;
L6:;
si0=l1;
si1=55296U;
si0=si0 < si1;
if(si0){
goto L8;
}
si0=l1;
si1=-8192U;
si0&=si1;
si1=57344U;
si0=si0 != si1;
if(si0){
goto L7;
}
L8:;
si0=l0;
si1=l1;
si2=63U;
si1&=si2;
si2=128U;
si1|=si2;
i32_store8(i->m0,(U64)si0+2U,si1);
si0=l0;
si1=l1;
si2=12U;
si1>>=(si2&31);
si2=224U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
si2=6U;
si1>>=(si2&31);
si2=63U;
si1&=si2;
si2=128U;
si1|=si2;
i32_store8(i->m0,(U64)si0+1U,si1);
si0=3U;
goto L0;
L7:;
si0=l1;
si1=-65536U;
si0+=si1;
si1=1048575U;
si0=si0 > si1;
if(si0){
goto L9;
}
si0=l0;
si1=l1;
si2=63U;
si1&=si2;
si2=128U;
si1|=si2;
i32_store8(i->m0,(U64)si0+3U,si1);
si0=l0;
si1=l1;
si2=18U;
si1>>=(si2&31);
si2=240U;
si1|=si2;
i32_store8(i->m0,(U64)si0,si1);
si0=l0;
si1=l1;
si2=6U;
si1>>=(si2&31);
si2=63U;
si1&=si2;
si2=128U;
si1|=si2;
i32_store8(i->m0,(U64)si0+2U,si1);
si0=l0;
si1=l1;
si2=12U;
si1>>=(si2&31);
si2=63U;
si1&=si2;
si2=128U;
si1|=si2;
i32_store8(i->m0,(U64)si0+1U,si1);
si0=4U;
goto L0;
L9:;
si0=0U;
si1=25U;
i32_store(i->m0,(U64)si0+3700U,si1);
L3:;
si0=-1U;
l3=si0;
L1:;
si0=l3;
L0:;
return si0;
}

U32 f51(exampleInstance*i,U32 l0) {
U32 l1=0;
U32 l2=0;
U32 l3=0;
U32 si0,si1,si2;
si0=l0;
l1=si0;
si0=l0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L2;
}
si0=l0;
si0=i32_load8_u(i->m0,(U64)si0);
if(si0){
goto L3;
}
si0=l0;
si1=l0;
si0-=si1;
goto L0;
L3:;
si0=l0;
si1=1U;
si0+=si1;
l1=si0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L2;
}
si0=l1;
si0=i32_load8_u(i->m0,(U64)si0);
si0=!(si0);
if(si0){
goto L1;
}
si0=l0;
si1=2U;
si0+=si1;
l1=si0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L2;
}
si0=l1;
si0=i32_load8_u(i->m0,(U64)si0);
si0=!(si0);
if(si0){
goto L1;
}
si0=l0;
si1=3U;
si0+=si1;
l1=si0;
si1=3U;
si0&=si1;
si0=!(si0);
if(si0){
goto L2;
}
si0=l1;
si0=i32_load8_u(i->m0,(U64)si0);
si0=!(si0);
if(si0){
goto L1;
}
si0=l0;
si1=4U;
si0+=si1;
l1=si0;
si1=3U;
si0&=si1;
if(si0){
goto L1;
}
L2:;
si0=l1;
si1=-4U;
si0+=si1;
l2=si0;
si0=l1;
si1=-5U;
si0+=si1;
l1=si0;
L4:;
{
si0=l1;
si1=4U;
si0+=si1;
l1=si0;
si0=l2;
si1=4U;
si0+=si1;
l2=si0;
si0=i32_load(i->m0,(U64)si0);
l3=si0;
si1=-1U;
si0^=si1;
si1=l3;
si2=-16843009U;
si1+=si2;
si0&=si1;
si1=-2139062144U;
si0&=si1;
si0=!(si0);
if(si0){
goto L4;
}
}
L5:;
{
si0=l1;
si1=1U;
si0+=si1;
l1=si0;
si0=l2;
si0=i32_load8_u(i->m0,(U64)si0);
l3=si0;
si0=l2;
si1=1U;
si0+=si1;
l2=si0;
si0=l3;
if(si0){
goto L5;
}
}
L1:;
si0=l1;
si1=l0;
si0-=si1;
L0:;
return si0;
}

U32 f38(exampleInstance*i,U32 l0) {
U32 l1=0;
U32 si0,si1,si2,si3;
si0=0U;
si0=i32_load(i->m0,(U64)si0+4776U);
l1=si0;
if(si0){
goto L1;
}
si0=4752U;
l1=si0;
si0=0U;
si1=4752U;
i32_store(i->m0,(U64)si0+4776U,si1);
L1:;
si0=0U;
si1=l0;
si2=l0;
si3=76U;
si2=si2 > si3;
si0=si2?si0:si1;
si1=1U;
si0<<=(si1&31);
si1=2816U;
si0+=si1;
si0=i32_load16_u(i->m0,(U64)si0);
si1=1249U;
si0+=si1;
si1=l1;
si1=i32_load(i->m0,(U64)si1+20U);
si0=f37(i,si0,si1);
L0:;
return si0;
}

U32 f21(exampleInstance*i,U32 l0,U32 l1) {
U32 l2=0;
U32 si0,si1,si2;
si0=i->g0;
si1=16U;
si0-=si1;
l2=si0;
i->g0=si0;
si0=l2;
si1=l1;
i32_store(i->m0,(U64)si0+12U,si1);
si0=3456U;
si1=l0;
si2=l1;
si0=f44(i,si0,si1,si2);
l1=si0;
si0=l2;
si1=16U;
si0+=si1;
i->g0=si0;
si0=l1;
L0:;
return si0;
}

void f18(exampleInstance*i,U32 l0) {
U32 si0;
si0=l0;
wasi_snapshot_preview1__proc_exit(i,si0);
UNREACHABLE;
L0:;
}

F64 f41(exampleInstance*i,F64 l0,U32 l1) {
U64 l2=0;
U32 l3=0;
U32 si0,si1,si2;
U64 sj0,sj1;
F64 sd0,sd1;
sd0=l0;
sj0=i64_reinterpret_f64(sd0);
l2=sj0;
sj1=52ULL;
sj0>>=(sj1&63);
si0=(U32)(sj0);
si1=2047U;
si0&=si1;
l3=si0;
si1=2047U;
si0=si0 == si1;
if(si0){
goto L1;
}
si0=l3;
if(si0){
goto L2;
}
sd0=l0;
sd1=0;
si0=sd0 != sd1;
if(si0){
goto L3;
}
si0=l1;
si1=0U;
i32_store(i->m0,(U64)si0,si1);
sd0=l0;
goto L0;
L3:;
sd0=l0;
sd1=1.8446744073709552e+19;
sd0*=sd1;
si1=l1;
sd0=f41(i,sd0,si1);
l0=sd0;
si0=l1;
si1=l1;
si1=i32_load(i->m0,(U64)si1);
si2=-64U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
sd0=l0;
goto L0;
L2:;
si0=l1;
si1=l3;
si2=-1022U;
si1+=si2;
i32_store(i->m0,(U64)si0,si1);
sj0=l2;
sj1=-9218868437227405313ULL;
sj0&=sj1;
sj1=4602678819172646912ULL;
sj0|=sj1;
sd0=f64_reinterpret_i64(sj0);
l0=sd0;
L1:;
sd0=l0;
L0:;
return sd0;
}

wasmFuncExport exampleFuncExports[2] = {
{(wasmFunc)f12,"_start"},
{NULL,NULL}
};

static void exampleInitMemories(exampleInstance* i, exampleInstance* parent) {
i->m0 = wasmMemoryAllocate(2, 65535, false);
LOAD_DATA((*i->m0), 1024U, d0, 2432);
LOAD_DATA((*i->m0), 3456U, d1, 236);
}

static void exampleInitTables(exampleInstance* i) {
U32 offset;
wasmTableAllocate(&i->t0, 5, 5);
offset=1U;
i->t0.data[offset+0]=(wasmFunc)&f26;
i->t0.data[offset+1]=(wasmFunc)&f24;
i->t0.data[offset+2]=(wasmFunc)&f28;
i->t0.data[offset+3]=(wasmFunc)&f30;
}

static void exampleInitGlobals(exampleInstance* i) {
i->g0=70336U;
i->g1=0U;
}

static void exampleInitImports(exampleInstance* i, void* resolve(const char* module, const char* name)) {
if (resolve == NULL) { return; }
}

wasmMemory*example_memory(exampleInstance* i){
return i->m0;
}

void example__start(exampleInstance*i){
f12(i);
}

exampleInstance* exampleNewChild(exampleInstance* self) {
exampleInstance* child = (exampleInstance*)calloc(1, sizeof(exampleInstance));
child->common.funcExports = self->common.funcExports;
child->common.resolveImports = self->common.resolveImports;
child->common.newChild = self->common.newChild;
exampleInitImports(child, self->common.resolveImports);
exampleInitMemories(child, self);
exampleInitTables(child);
exampleInitGlobals(child);
return child;
}

void exampleInstantiate(exampleInstance* i, void* resolveImports(const char* module, const char* name)) {
i->common.funcExports = exampleFuncExports;
i->common.resolveImports = resolveImports;
i->common.newChild = (struct wasmModuleInstance* (*)(struct wasmModuleInstance*))exampleNewChild;
exampleInitImports(i, resolveImports);
exampleInitMemories(i, NULL);
exampleInitTables(i);
exampleInitGlobals(i);
}

void exampleFreeInstance(exampleInstance* i) {
wasmMemoryFree(i->m0);
wasmTableFree(&i->t0);
}

