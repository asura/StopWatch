#!/bin/sh

. ./scripts/base_functions.sh

info "ソースファイルの改行コード確認"

count=`(find . -type f \( -name "*.h" -o -name "*.cpp" \) | xargs grep -lzUP '\r\n') 2>/dev/null | tee /dev/tty | wc -l`

if [ "$count" -eq "0" ]
then
  ok "CRLFなし"
else
  ng "CRLFあり(${count}ファイル)"
  exit 1
fi
