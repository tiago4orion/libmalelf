/*
 * The libmalelf is an evil library that could be used for good! It was
 * developed with the intent to assist in the process of infecting
 * binaries and provide a safe way to analyze malwares.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef MALELF_PHDR_H
#define MALELF_PHDR_H

#include <elf.h>

#include "types.h"

MALELF_BEGIN_DECLS

#define MALELF_PHDR_SIZE(class) \
        ((class == MALELF_ELF32) ? sizeof(Elf32_Phdr) : sizeof(Elf64_Phdr))

/*!
 * \File phdr.h
 * \brief A class used to control the program headers.
 *
 * The MalelfPhdr union is an opaque data type. It
 * should only be accessed via the following functions.
 *
 */

typedef struct {
        union {
                Elf32_Phdr *h32;    /*!< 32-bits ELF Program Headers */
                Elf64_Phdr *h64;    /*!< 64-bits ELF Program Headers */
        } uhdr;
        _u8 class;          /*!< Architeture class */
}MalelfPhdr;

typedef struct {
        _u32 type;
        _u8 class;
        _u32 index;
        _u8 *mem;
        _u32 offset;
        _u32 size;
        MalelfPhdr *phdr;
} MalelfSegment;


extern _u32 malelf_phdr_dump(Elf32_Phdr *elf_phdr);


/*! Get p_type member from Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param type Type saved.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if type was successful set,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_get_type(MalelfPhdr *phdr, _u32 *type, _u32 index);


/*! Get p_offset member from Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param offset Offset saved.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if offset was successful set,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_get_offset(MalelfPhdr *phdr, _u32 *offset, _u32 index);


/*! Get p_vaddr member from Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param vaddr Vaddr saved.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if vaddr was successful set,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_get_vaddr(MalelfPhdr *phdr, _u32 *vaddr, _u32 index);


/*! Get p_addr member from Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param paddr Paddr saved.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if paddr was successful set,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_get_paddr(MalelfPhdr *phdr, _u32 *paddr, _u32 index);


/*! Get p_filesz member from Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param filesz Filesz saved.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if filesz was successful set,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_get_filesz(MalelfPhdr *phdr, _u32 *filesz, _u32 index);


/*! Get p_memsz member from Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param memsz Memsz saved.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if memsz was successful set,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_get_memsz(MalelfPhdr *phdr, _u32 *memsz, _u32 index);


/*! Get p_flags member from Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param flags Flags saved.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if flags was successful set,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_get_flags(MalelfPhdr *phdr, _u32 *flags, _u32 index);


/*! Get p_align member from Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param align Align saved.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if align was successful set,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_get_align(MalelfPhdr *phdr, _u32 *align, _u32 index);


/*! Set new p_type on the Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param type New type.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if new type was successful saved,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_set_type(MalelfPhdr *phdr, _u32 type, _u32 index);


/*! Set p_align on the Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param align New align.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if new align was successful saved,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_set_align(MalelfPhdr *phdr, _u32 align, _u32 index);


/*! Set p_flags on the Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param align New flags.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if new flags was successful saved,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_set_flags(MalelfPhdr *phdr, _u32 flags, _u32 index);


/*! Set p_memsz on the Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param align New memsz.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if new memsz was successful saved,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_set_memsz(MalelfPhdr *phdr, _u32 memsz, _u32 index);


/*! Set p_offset on the Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param align New offset.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if new offset was successful saved,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_set_offset(MalelfPhdr *phdr, _u32 offset, _u32 index);


/*! Set p_vaddr on the Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param align New vaddr.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if new vaddr was successful saved,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_set_vaddr(MalelfPhdr *phdr, _u32 vaddr, _u32 index);


/*! Set p_paddr on the Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param align New paddr.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if new paddr was successful saved,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_set_paddr(MalelfPhdr *phdr, _u32 paddr, _u32 index);


/*! Set p_filesz on the Program Header Table.
 *
 *  \param phdr A valid MalelfPhdr object.
 *  \param align New filesz.
 *  \param index The index of segment.
 *
 *  \return MALELF_SUCCESS if new filesz was successful saved,
 *          otherwise returns MALELF_ERROR.
 */
extern _u32 malelf_phdr_set_filesz(MalelfPhdr *phdr, _u32 filesz, _u32 index);


MALELF_END_DECLS


#endif /* MALELF_PHDR_H */
