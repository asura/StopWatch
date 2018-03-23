info() {
  d=`date +"%Y/%m/%d %H:%M:%S"`
  # 6:Cyan
  (>&2 echo -e "\e[36m[$d] $1\e[m")
}

ok() {
  d=`date +"%Y/%m/%d %H:%M:%S"`
  # 2:Green
  (>&2 echo -e "\e[32m[$d] $1\e[m")
}

ng() {
  d=`date +"%Y/%m/%d %H:%M:%S"`
  # 1:Red
  (>&2 echo -e "\e[31m[$d] $1\e[m")
}
