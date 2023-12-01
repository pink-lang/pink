// TODO: remove this file someday

#define __USE_MINGW_ANSI_STDIO 1
#define _CRT_SECURE_NO_WARNINGS

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef MAX_PATH
#   if defined _MAX_PATH
#       define MAX_PATH _MAX_PATH
#   elif defined PATH_MAX
#       define MAX_PATH PATH_MAX
#   else
#       error "No suitable MAX_PATH surrogate"
#   endif
#endif

struct src_pink_Operand;
struct src_pink_Type;

bool cast_operand(struct src_pink_Operand *operand, struct src_pink_Type *type);

#ifdef _WIN32
#   include "out_pink_win32.c"
#else
#   include "out_pink_linux.c"
#endif

#define CASE(k, t) \
    case k: \
        switch (type->kind) { \
        case SRC_PINK_CMPL_TYPE_BOOL: \
            operand->val.b = (bool)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_CHAR: \
            operand->val.c = (char)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_UCHAR: \
            operand->val.uc = (unsigned char)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_SCHAR: \
            operand->val.sc = (signed char)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_SHORT: \
            operand->val.s = (short)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_USHORT: \
            operand->val.us = (unsigned short)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_INT: \
        case SRC_PINK_CMPL_TYPE_ENUM: \
            operand->val.i = (int)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_UINT: \
            operand->val.u = (unsigned)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_LONG: \
            operand->val.l = (long)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_ULONG: \
            operand->val.ul = (unsigned long)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_LLONG: \
            operand->val.ll = (long long)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_ULLONG: \
            operand->val.ull = (unsigned long long)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_PTR: \
            operand->val.p = (uintptr_t)operand->val.t; \
            break; \
        case SRC_PINK_CMPL_TYPE_FLOAT: \
        case SRC_PINK_CMPL_TYPE_DOUBLE: \
            break; \
        default: \
            operand->is_const = false; \
            break; \
        } \
        break;

bool cast_operand(src_pink_Operand *operand, src_pink_Type *type) {
    src_pink_Type *qual_type = type;
    type = src_pink_unqualify_type(type);
    operand->type = src_pink_unqualify_type(operand->type);
    if (operand->type != type) {
        if (!src_pink_is_castable(operand, type)) {
            return false;
        }
        if (operand->is_const) {
            if (src_pink_is_floating_type(operand->type)) {
                operand->is_const = !src_pink_is_integer_type(type);
            } else {
                if (type->kind == SRC_PINK_CMPL_TYPE_ENUM) {
                    type = type->base;
                }
                src_pink_Type *operand_type = operand->type;
                if (operand_type->kind == SRC_PINK_CMPL_TYPE_ENUM) {
                    operand_type = operand_type->base;
                }
                switch (operand_type->kind) {
                CASE(SRC_PINK_CMPL_TYPE_BOOL, b)
                CASE(SRC_PINK_CMPL_TYPE_CHAR, c)
                CASE(SRC_PINK_CMPL_TYPE_UCHAR, uc)
                CASE(SRC_PINK_CMPL_TYPE_SCHAR, sc)
                CASE(SRC_PINK_CMPL_TYPE_SHORT, s)
                CASE(SRC_PINK_CMPL_TYPE_USHORT, us)
                CASE(SRC_PINK_CMPL_TYPE_INT, i)
                CASE(SRC_PINK_CMPL_TYPE_UINT, u)
                CASE(SRC_PINK_CMPL_TYPE_LONG, l)
                CASE(SRC_PINK_CMPL_TYPE_ULONG, ul)
                CASE(SRC_PINK_CMPL_TYPE_LLONG, ll)
                CASE(SRC_PINK_CMPL_TYPE_ULLONG, ull)
                CASE(SRC_PINK_CMPL_TYPE_PTR, p)
                default:
                    operand->is_const = false;
                    break;
                }
            }
        }
    }
    operand->type = qual_type;
    return true;
}

#undef CASE
