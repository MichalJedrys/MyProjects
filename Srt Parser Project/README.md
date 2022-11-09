# SRT Parser

## Description

My own implementation of .srt file parser. It accepts .srt files and produces simple .txt files containing timestamps and corresponding lines of text.

## Testing

Program is tested for the following situations:
- Absence of two "new lines" at the end of the file
- Incorrect record numbers
- Nesting of lines
- Intersection of lines
- Incorrect time stamps
