/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bits_utils
*/

int extract_signed4bit(int val)
{
    val &= 0xF;
    if (val & 0x8)
        return (val | ~0xF);
    return (val);
}
