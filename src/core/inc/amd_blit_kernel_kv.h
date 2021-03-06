////////////////////////////////////////////////////////////////////////////////
//
// The University of Illinois/NCSA
// Open Source License (NCSA)
// 
// Copyright (c) 2014-2015, Advanced Micro Devices, Inc. All rights reserved.
// 
// Developed by:
// 
//                 AMD Research and AMD HSA Software Development
// 
//                 Advanced Micro Devices, Inc.
// 
//                 www.amd.com
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal with the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
// 
//  - Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimers.
//  - Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimers in
//    the documentation and/or other materials provided with the distribution.
//  - Neither the names of Advanced Micro Devices, Inc,
//    nor the names of its contributors may be used to endorse or promote
//    products derived from this Software without specific prior written
//    permission.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS WITH THE SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef HSA_RUNTIME_CORE_INC_AMD_BLIT_KERNEL_KV_H_
#define HSA_RUNTIME_CORE_INC_AMD_BLIT_KERNEL_KV_H_

#include <stddef.h>

#define HSA_VECTOR_COPY_KV_AKC_SIZE 368
#define HSA_VECTOR_COPY_KV_AKC_OFFSET 256

/*****HSAIL code of the ISA in ::kVectorCopyRawKv.
module &m:1:0:$full:$large:$default;

prog kernel &__vector_copy_kernel(
  kernarg_u64 %src,
  kernarg_u64 %dst,
  kernarg_u64 %size)
{
  @__vector_copy_kernel_entry:
  // BB#0:                                // %entry
  workitemabsid_u32	$s0, 0;
  cvt_u64_u32	$d0, $s0;
  ld_kernarg_align(8)_width(all)_u64	$d1, [%size];
  cmp_ge_b1_u64	$c0, $d0, $d1;
  cbr_b1	$c0, @BB0_2;
  // BB#1:                                // %if.end
  ld_kernarg_align(8)_width(all)_u64	$d1, [%src];
  ld_kernarg_align(8)_width(all)_u64	$d2, [%dst];
  add_u64	$d2, $d2, $d0;
  add_u64	$d0, $d1, $d0;
  ld_global_u8	$s0, [$d0];
  st_global_u8	$s0, [$d2];

  @BB0_2:
  // %return
  ret;
};
*/

static char kVectorCopyRawKv[] = {
    127,  69,   76,   70,   2,   1,   1,   64,   0,    0,    0,   0,    0,
    0,    0,    0,    1,    0,   -32, 0,   1,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   64,  0,    0,    0,    0,   0,    0,
    0,    -104, 3,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    64,   0,    56,   0,    1,   0,   64,  0,    6,    0,    5,   0,    3,
    0,    0,    96,   6,    0,   0,   0,   0,    1,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   112, 1,   0,    0,    0,    0,   0,    0,
    112,  1,    0,    0,    0,   0,   0,   0,    0,    1,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    1,    0,   0,    0,
    0,    0,    0,    0,    1,   0,   0,   0,    0,    0,    0,   0,    0,
    1,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   65,  0,   -116, 0,    -112, 0,   0,    0,
    11,   0,    10,   0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    24,   0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    11,   0,    5,   0,   5,   0,    0,    0,    9,   0,    0,
    0,    0,    0,    0,    0,   3,   0,   0,    6,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   1,   5,   0,    -64,  127,  0,   -116, -65,
    0,    -1,   -128, -109, 0,   0,   16,  0,    0,    8,    0,   -109, 0,
    0,    0,    74,   4,    7,   64,  -64, -128, 2,    2,    126, 127,  0,
    -116, -65,  0,    0,    -56, 125, 106, 36,   -128, -66,  15,  0,    -120,
    -65,  0,    7,    -126, -64, 127, 0,   -116, -65,  4,    0,   2,    74,
    5,    2,    4,    126,  2,   106, 80,  -46,  2,    1,    -87, 1,    0,
    0,    32,   -36,  1,    0,   0,   1,   6,    0,    6,    74,  7,    2,
    4,    126,  4,    106,  80,  -46, 2,   1,    -87,  1,    112, 0,    -116,
    -65,  0,    0,    96,   -36, 3,   1,   0,    0,    0,    0,   -127, -65,
    3,    0,    0,    0,    8,   0,   0,   0,    1,    0,    0,   0,    65,
    77,   68,   0,    1,    0,   0,   0,   0,    0,    0,    0,   3,    0,
    0,    0,    12,   0,    0,   0,   2,   0,    0,    0,    65,  77,   68,
    0,    1,    0,    0,    0,   0,   0,   0,    0,    1,    1,   1,    0,
    3,    0,    0,    0,    28,  0,   0,   0,    3,    0,    0,   0,    65,
    77,   68,   0,    4,    0,   7,   0,   7,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   65,  77,   68,   0,    65,  77,   68,
    71,   80,   85,   0,    0,   3,   0,   0,    0,    40,   0,   0,    0,
    4,    0,    0,    0,    65,  77,  68,  0,    26,   0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   65,   77,   68,   32,  72,   83,
    65,   32,   82,   117,  110, 116, 105, 109,  101,  32,   70,  105,  110,
    97,   108,  105,  122,  101, 114, 0,   0,    0,    38,   95,  95,   118,
    101,  99,   116,  111,  114, 95,  99,  111,  112,  121,  95,  107,  101,
    114,  110,  101,  108,  0,   95,  95,  104,  115,  97,   95,  115,  101,
    99,   116,  105,  111,  110, 46,  104, 115,  97,   116,  101, 120,  116,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    26,   0,   1,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    22,   0,   0,   0,   3,    0,    1,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    46,   104,  115, 97,  116, 101,  120,  116,  0,   46,   110,
    111,  116,  101,  0,    46,  115, 116, 114,  116,  97,   98,  0,    46,
    115,  121,  109,  116,  97,  98,  0,   46,   115,  104,  115, 116,  114,
    116,  97,   98,   0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    1,    0,   0,    0,
    1,    0,    0,    0,    7,   0,   -64, 0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    1,    0,    0,   0,    0,
    0,    0,    112,  1,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   1,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    10,   0,    0,   0,    7,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   112, 2,    0,    0,    0,   0,    0,
    0,    -104, 0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    4,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   16,   0,    0,    0,   3,    0,
    0,    0,    32,   0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   8,   3,   0,    0,    0,    0,   0,    0,
    44,   0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    1,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    0,   0,   24,  0,    0,    0,    2,   0,    0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,    56,  3,   0,   0,    0,    0,    0,   0,    48,
    0,    0,    0,    0,    0,   0,   0,   3,    0,    0,    0,   0,    0,
    0,    0,    8,    0,    0,   0,   0,   0,    0,    0,    24,  0,    0,
    0,    0,    0,    0,    0,   32,  0,   0,    0,    3,    0,   0,    0,
    32,   0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    104,  3,   0,   0,   0,    0,    0,    0,   42,   0,
    0,    0,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    1,    0,    0,    0,   0,   0,   0,    0,    0,    0,   0,    0,
    0,    0,    0,    0,
};
extern char* const kVectorCopyKvObject = &kVectorCopyRawKv[0];
extern size_t const kVectorCopyKvObjectSize = sizeof(kVectorCopyRawKv);

#define HSA_VECTOR_COPY_ALIGNED_KV_AKC_SIZE 436
#define HSA_VECTOR_COPY_ALIGNED_KV_AKC_OFFSET 256

/*****HSAIL code of the ISA in ::kVectorCopyAlignedRawKv.
module &m:1:0:$full:$large:$default;
extension "amd:gcn";

prog kernel &__copy_buffer_aligned_kernel(
  kernarg_u64 %src,
  kernarg_u64 %dst,
  kernarg_u64 %size,
  kernarg_u32 %use_vector)
{
  @__copy_buffer_aligned_kernel_entry:
  // BB#0:                                // %entry
  workitemabsid_u32	$s0, 0;
  cvt_u64_u32	$d0, $s0;
  ld_kernarg_align(8)_width(all)_u64	$d1, [%size];
  cmp_ge_b1_u64	$c0, $d0, $d1;
  cbr_b1	$c0, @LBB0_4;
  // BB#1:                                // %if.end
  ld_kernarg_align(8)_width(all)_u64	$d2, [%dst];
  ld_kernarg_align(8)_width(all)_u64	$d1, [%src];
  ld_kernarg_align(4)_width(all)_u32	$s0, [%use_vector];
  cmp_ne_b1_s32	$c0, $s0, 1;
  cbr_b1	$c0, @LBB0_3;
  // BB#2:                                // %if.then2
  shl_u64	$d0, $d0, 4;
  add_u64	$d2, $d2, $d0;
  add_u64	$d0, $d1, $d0;
  ld_v4_global_align(16)_const_u32	($s0, $s1, $s2, $s3), [$d0];
  st_v4_global_align(16)_u32	($s0, $s1, $s2, $s3), [$d2];
  br	@LBB0_4;

  @LBB0_3:
  // %if.else
  shl_u64	$d0, $d0, 2;
  add_u64	$d2, $d2, $d0;
  add_u64	$d0, $d1, $d0;
  ld_global_align(4)_const_u32	$s0, [$d0];
  st_global_align(4)_u32	$s0, [$d2];

  @LBB0_4:
  // %if.end6
  ret;
};
*/

static char kVectorCopyAlignedRawKv[] = {
    127,  69,   76,   70,   2,   1,   1,    64,   0,    0,    0,    0,    0,
    0,    0,    0,    1,    0,   -32, 0,    1,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   64,   0,    0,    0,    0,    0,    0,
    0,    -8,   3,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    64,   0,    56,   0,    1,   0,   64,   0,    6,    0,    5,    0,    3,
    0,    0,    96,   6,    0,   0,   0,    0,    1,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   -76, 1,    0,    0,    0,    0,    0,    0,
    -76,  1,    0,    0,    0,   0,   0,    0,    0,    1,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    1,    0,    0,    0,
    1,    0,    0,    0,    1,   0,   0,    0,    0,    0,    0,    0,    0,
    1,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   65,  0,    -84,  0,    -112, 0,    0,    0,
    11,   0,    10,   0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    32,   0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    11,   0,    7,   0,   7,    0,    0,    0,    9,    0,    0,
    0,    0,    0,    0,    0,   4,   4,    4,    6,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   1,   5,    0,    -64,  127,  0,    -116, -65,
    0,    -1,   -128, -109, 0,   0,   16,   0,    0,    8,    0,    -109, 0,
    0,    0,    74,   4,    7,   64,  -64,  -128, 2,    2,    126,  127,  0,
    -116, -65,  0,    0,    -56, 125, 106,  36,   -128, -66,  32,   0,    -120,
    -65,  6,    7,    1,    -64, 0,   7,    -126, -64,  127,  0,    -116, -65,
    2,    -127, 0,    -65,  14,  0,   -124, -65,  0,    0,    -62,  -46,  0,
    9,    1,    0,    4,    0,   4,   74,   5,    2,    6,    126,  3,    3,
    6,    80,   0,    0,    56,  -36, 2,    0,    0,    2,    6,    0,    0,
    74,   7,    2,    12,   126, 6,   3,    2,    80,   112,  0,    -116, -65,
    0,    0,    120,  -36,  0,   2,   0,    0,    13,   0,    -126, -65,  0,
    0,    -62,  -46,  0,    5,   1,   0,    4,    0,    4,    74,   5,    2,
    6,    126,  3,    3,    6,   80,  0,    0,    48,   -36,  2,    0,    0,
    2,    6,    0,    0,    74,  7,   2,    6,    126,  3,    3,    2,    80,
    112,  0,    -116, -65,  0,   0,   112,  -36,  0,    2,    0,    0,    0,
    0,    -127, -65,  0,    0,   0,   0,    4,    0,    0,    0,    8,    0,
    0,    0,    1,    0,    0,   0,   65,   77,   68,   0,    1,    0,    0,
    0,    0,    0,    0,    0,   4,   0,    0,    0,    12,   0,    0,    0,
    2,    0,    0,    0,    65,  77,  68,   0,    1,    0,    0,    0,    0,
    0,    0,    0,    1,    1,   1,   0,    4,    0,    0,    0,    25,   0,
    0,    0,    5,    0,    0,   0,   65,   77,   68,   0,    22,   0,    45,
    104,  115,  97,   95,   99,  97,  108,  108,  95,   99,   111,  110,  118,
    101,  110,  116,  105,  111, 110, 61,   0,    0,    0,    0,    0,    4,
    0,    0,    0,    30,   0,   0,   0,    3,    0,    0,    0,    65,   77,
    68,   0,    4,    0,    7,   0,   7,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   65,  77,   68,   0,    65,   77,   68,   71,
    80,   85,   0,    0,    0,   0,   0,    0,    4,    0,    0,    0,    8,
    0,    0,    0,    4,    0,   0,   0,    65,   77,   68,   0,    -32,  101,
    -118, -12,  -1,   127,  0,   0,   38,   95,   95,   99,   111,  112,  121,
    95,   98,   117,  102,  102, 101, 114,  95,   97,   108,  105,  103,  110,
    101,  100,  95,   107,  101, 114, 110,  101,  108,  0,    95,   95,   104,
    115,  97,   95,   115,  101, 99,  116,  105,  111,  110,  46,   104,  115,
    97,   116,  101,  120,  116, 0,   0,    0,    0,    0,    0,    0,    0,
    0,    26,   0,    1,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    -76,  1,    0,    0,    0,   0,   0,    0,    30,   0,    0,    0,    3,
    0,    1,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    46,   104,  115,  97,   116,  101,
    120,  116,  0,    46,   110, 111, 116,  101,  0,    46,   115,  116,  114,
    116,  97,   98,   0,    46,  115, 121,  109,  116,  97,   98,   0,    46,
    115,  104,  115,  116,  114, 116, 97,   98,   0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,    0,    0,   1,   0,    0,    0,    7,    0,    -64,  0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    1,    0,    0,    0,    0,   0,   0,    -76,  1,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    1,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    10,   0,    0,    0,    7,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    -72,  2,
    0,    0,    0,    0,    0,   0,   -88,  0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    8,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    0,    16,
    0,    0,    0,    3,    0,   0,   0,    32,   0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    96,   3,    0,
    0,    0,    0,    0,    0,   52,  0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    1,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    0,    0,    24,   0,
    0,    0,    2,    0,    0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,    -104, 3,    0,    0,
    0,    0,    0,    0,    48,  0,   0,    0,    0,    0,    0,    0,    3,
    0,    0,    0,    0,    0,   0,   0,    8,    0,    0,    0,    0,    0,
    0,    0,    24,   0,    0,   0,   0,    0,    0,    0,    32,   0,    0,
    0,    3,    0,    0,    0,   32,  0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    -56,  3,    0,    0,    0,
    0,    0,    0,    42,   0,   0,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   1,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   0,   0,    0,    0,
};
extern char* const kVectorCopyAlignedKvObject = &kVectorCopyAlignedRawKv[0];
extern size_t const kVectorCopyAlignedKvObjectSize =
    sizeof(kVectorCopyAlignedRawKv);

#define HSA_FILL_MEMORY_KV_AKC_SIZE 352
#define HSA_FILL_MEMORY_KV_AKC_OFFSET 256

/*****HSAIL code of the ISA in ::kFillMemoryRawKv.
module &m:1:0:$full:$large:$default;
extension "amd:gcn";

prog kernel &__fill_memory_kernel(
kernarg_u64 %ptr,
kernarg_u64 %num,
kernarg_u32 %value)
{
@__fill_memory_kernel_entry:
// BB#0:                                // %entry
workitemabsid_u32	$s0, 0;
cvt_u64_u32	$d0, $s0;
ld_kernarg_align(8)_width(all)_u64	$d1, [%num];
cmp_ge_b1_u64	$c0, $d0, $d1;
cbr_b1	$c0, @LBB0_2;
// BB#1:                                // %if.end
ld_kernarg_align(8)_width(all)_u64	$d1, [%ptr];
ld_kernarg_align(4)_width(all)_u32	$s0, [%value];
shl_u64	$d0, $d0, 2;
add_u64	$d0, $d1, $d0;
st_global_align(4)_u32	$s0, [$d0];

@LBB0_2:
// %return
ret;
};
*/

static char kFillMemoryRawKv[] = {
    127,  69,   76,  70,  2,    1,    1,   64,  0,    0,   0,   0,   0,    0,
    0,    0,    1,   0,   -32,  0,    1,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   64,   0,    0,   0,   0,    0,   0,   0,   -104, 3,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   64,  0,   56,   0,
    1,    0,    64,  0,   6,    0,    5,   0,   3,    0,   0,   96,  6,    0,
    0,    0,    0,   1,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   96,   1,
    0,    0,    0,   0,   0,    0,    96,  1,   0,    0,   0,   0,   0,    0,
    0,    1,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   1,    0,    0,   0,   1,    0,   0,   0,   1,    0,
    0,    0,    0,   0,   0,    0,    0,   1,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   64,  0,   -84,  0,
    -112, 0,    0,   0,   11,   0,    10,  0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    32,  0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   11,   0,    3,   0,   3,    0,   0,   0,   9,    0,
    0,    0,    0,   0,   0,    0,    4,   4,   4,    6,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   1,    5,   0,   -64, 127,  0,
    -116, -65,  0,   -1,  -128, -109, 0,   0,   16,   0,   0,   8,   0,    -109,
    0,    0,    0,   74,  2,    7,    64,  -64, -128, 2,   2,   126, 127,  0,
    -116, -65,  0,   0,   -56,  125,  106, 36,  -128, -66, 11,  0,   -120, -65,
    0,    7,    65,  -64, 4,    7,    2,   -64, 0,    0,   -62, -46, 0,    5,
    1,    0,    127, 0,   -116, -65,  2,   0,   0,    74,  3,   2,   4,    126,
    2,    3,    2,   80,  4,    2,    4,   126, 0,    0,   112, -36, 0,    2,
    0,    0,    0,   0,   -127, -65,  4,   0,   0,    0,   8,   0,   0,    0,
    1,    0,    0,   0,   65,   77,   68,  0,   1,    0,   0,   0,   0,    0,
    0,    0,    4,   0,   0,    0,    12,  0,   0,    0,   2,   0,   0,    0,
    65,   77,   68,  0,   1,    0,    0,   0,   0,    0,   0,   0,   1,    1,
    1,    0,    4,   0,   0,    0,    25,  0,   0,    0,   5,   0,   0,    0,
    65,   77,   68,  0,   22,   0,    45,  104, 115,  97,  95,  99,  97,   108,
    108,  95,   99,  111, 110,  118,  101, 110, 116,  105, 111, 110, 61,   0,
    0,    0,    0,   0,   4,    0,    0,   0,   30,   0,   0,   0,   3,    0,
    0,    0,    65,  77,  68,   0,    4,   0,   7,    0,   7,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   65,   77,  68,  0,   65,   77,
    68,   71,   80,  85,  0,    0,    0,   0,   0,    0,   4,   0,   0,    0,
    8,    0,    0,   0,   4,    0,    0,   0,   65,   77,  68,  0,   48,   123,
    44,   -103, -4,  127, 0,    0,    38,  95,  95,   102, 105, 108, 108,  95,
    109,  101,  109, 111, 114,  121,  95,  107, 101,  114, 110, 101, 108,  0,
    95,   95,   104, 115, 97,   95,   115, 101, 99,   116, 105, 111, 110,  46,
    104,  115,  97,  116, 101,  120,  116, 0,   0,    0,   0,   0,   0,    0,
    0,    0,    26,  0,   1,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    96,   1,    0,   0,   0,    0,    0,   0,   22,   0,   0,   0,   3,    0,
    1,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    46,   104, 115, 97,   116, 101, 120, 116,  0,
    46,   110,  111, 116, 101,  0,    46,  115, 116,  114, 116, 97,  98,   0,
    46,   115,  121, 109, 116,  97,   98,  0,   46,   115, 104, 115, 116,  114,
    116,  97,   98,  0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   1,    0,    0,   0,   1,    0,   0,   0,   7,    0,
    -64,  0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    1,    0,   0,   0,    0,    0,   0,   96,   1,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   1,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   10,   0,
    0,    0,    7,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   96,   2,   0,   0,   0,    0,
    0,    0,    -88, 0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   8,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    16,  0,   0,    0,   3,   0,   0,    0,
    32,   0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    8,   3,   0,    0,    0,   0,   0,    0,   44,  0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   1,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    24,   0,    0,   0,   2,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   56,  3,   0,    0,
    0,    0,    0,   0,   48,   0,    0,   0,   0,    0,   0,   0,   3,    0,
    0,    0,    0,   0,   0,    0,    8,   0,   0,    0,   0,   0,   0,    0,
    24,   0,    0,   0,   0,    0,    0,   0,   32,   0,   0,   0,   3,    0,
    0,    0,    32,  0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,    0,   0,   104,  3,    0,   0,   0,    0,   0,   0,   42,   0,
    0,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    1,    0,    0,   0,   0,    0,    0,   0,   0,    0,   0,   0,   0,    0,
    0,    0,
};

extern char* const kFillMemoryKvObject = &kFillMemoryRawKv[0];
extern size_t const kFillMemoryKvObjectSize = sizeof(kFillMemoryRawKv);
#endif  // header guard