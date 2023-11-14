# Maksym Khodakov TTP-32
### System programming Laboratory work #6

####  1) commands to get a flame graph
git clone https://github.com/brendangregg/FlameGraph  
perf record -F 50 --call-graph dwarf ./main  
perf script | /home/jovakinn/CLionProjects/flame/FlameGraph/stackcollapse-perf.pl |  
/home/jovakinn/CLionProjects/flame/FlameGraph/stackcollapse-recursive.pl |  
/home/jovakinn/CLionProjects/flame/FlameGraph/flamegraph.pl > outMain.svg
