# Maksym Khodakov TTP-32
### System programming Laboratory work #6

###  1) Commands to get a flame graph
git clone https://github.com/brendangregg/FlameGraph  
perf record -F 50 --call-graph dwarf ./main  
perf script | /home/jovakinn/CLionProjects/flame/FlameGraph/stackcollapse-perf.pl |  
/home/jovakinn/CLionProjects/flame/FlameGraph/stackcollapse-recursive.pl |  
/home/jovakinn/CLionProjects/flame/FlameGraph/flamegraph.pl > outMain.svg

### 2) Commands for statistics
/usr/bin/time --verbose ./main

---

        Command being timed: "./main"
        User time (seconds): 2.20
        System time (seconds): 0.54
        Percent of CPU this job got: 6%
        Elapsed (wall clock) time (h:mm:ss or m:ss): 0:42.32
        Average shared text size (kbytes): 0
        Average unshared data size (kbytes): 0
        Average stack size (kbytes): 0
        Average total size (kbytes): 0
        Maximum resident set size (kbytes): 3456
        Average resident set size (kbytes): 0
        Major (requiring I/O) page faults: 1
        Minor (reclaiming a frame) page faults: 136
        Voluntary context switches: 4523
        Involuntary context switches: 1791
        Swaps: 0
        File system inputs: 32
        File system outputs: 0
        Socket messages sent: 0
        Socket messages received: 0
        Signals delivered: 0
        Page size (bytes): 4096
        Exit status: 0
---
/usr/bin/time --verbose ./optimized

---
        Command being timed: "./optimized"
        User time (seconds): 0.58
        System time (seconds): 0.58
        Percent of CPU this job got: 2%
        Elapsed (wall clock) time (h:mm:ss or m:ss): 0:47.55
        Average shared text size (kbytes): 0
        Average unshared data size (kbytes): 0
        Average stack size (kbytes): 0
        Average total size (kbytes): 0
        Maximum resident set size (kbytes): 3456
        Average resident set size (kbytes): 0
        Major (requiring I/O) page faults: 1
        Minor (reclaiming a frame) page faults: 135
        Voluntary context switches: 4523
        Involuntary context switches: 1770
        Swaps: 0
        File system inputs: 32
        File system outputs: 0
        Socket messages sent: 0
        Socket messages received: 0
        Signals delivered: 0
        Page size (bytes): 4096
        Exit status: 0
---

perf stat -d ./main
---
Performance counter stats for './main':

          2 759,46 msec task-clock                       #    0,065 CPUs utilized             
             6 770      context-switches                 #    2,453 K/sec                     
                 0      cpu-migrations                   #    0,000 /sec                      
               125      page-faults                      #   45,299 /sec                      
     <not supported>      cycles                                                                
     <not supported>      instructions                                                          
     <not supported>      branches                                                              
     <not supported>      branch-misses                                                         
     <not supported>      L1-dcache-loads                                                       
     <not supported>      L1-dcache-load-misses                                                 
     <not supported>      LLC-loads                                                             
     <not supported>      LLC-load-misses                                                       

      42,451228486 seconds time elapsed

       2,157220000 seconds user
       0,604571000 seconds sys

---

perf stat -d ./main
---
Performance counter stats for './optimized':

          1 169,81 msec task-clock                       #    0,032 CPUs utilized             
             6 575      context-switches                 #    5,621 K/sec                     
                 0      cpu-migrations                   #    0,000 /sec                      
               125      page-faults                      #  106,855 /sec                      
     <not supported>      cycles                                                                
     <not supported>      instructions                                                          
     <not supported>      branches                                                              
     <not supported>      branch-misses                                                         
     <not supported>      L1-dcache-loads                                                       
     <not supported>      L1-dcache-load-misses                                                 
     <not supported>      LLC-loads                                                             
     <not supported>      LLC-load-misses                                                       

      36,861763906 seconds time elapsed

       0,592626000 seconds user
       0,581785000 seconds sys
---


perf record ./main  
perf report

---
