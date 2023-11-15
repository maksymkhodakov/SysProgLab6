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


perf record ./main perf report
---
        Overhead  Command  Shared Object         Symbol
        40,57%  main     main                  [.] gcd
        29,01%  main     [kernel.kallsyms]     [k] finish_task_switch.isra.0
        7,11%  main     libc.so.6             [.] __GI___libc_write
        2,55%  main     [kernel.kallsyms]     [k] _raw_spin_unlock_irqrestore
        2,25%  main     [kernel.kallsyms]     [k] syscall_enter_from_user_mode
        2,18%  main     libc.so.6             [.] _IO_fwrite
        1,50%  main     [kernel.kallsyms]     [k] process_output_block
        0,96%  main     [vboxguest]           [k] vbg_req_perform
        0,60%  main     [kernel.kallsyms]     [k] n_tty_write
        0,58%  main     libc.so.6             [.] _IO_file_xsputn@@GLIBC_2.2.5
        0,56%  main     [kernel.kallsyms]     [k] file_tty_write.constprop.0
        0,56%  main     libstdc++.so.6.0.30   [.] std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>
        0,51%  main     [kernel.kallsyms]     [k] pty_write
        0,51%  main     libc.so.6             [.] _IO_fflush
        0,49%  main     [kernel.kallsyms]     [k] __check_heap_object
        0,49%  main     [kernel.kallsyms]     [k] pty_write_room
        0,45%  main     [kernel.kallsyms]     [k] queue_work_on
        0,45%  main     libstdc++.so.6.0.30   [.] std::ostream::put
        0,43%  main     [kernel.kallsyms]     [k] vfs_write
        0,39%  main     [kernel.kallsyms]     [k] apparmor_file_permission
        0,36%  main     libstdc++.so.6.0.30   [.] std::ostream::sentry::sentry
        0,34%  main     [kernel.kallsyms]     [k] __fget_light
        0,32%  main     libstdc++.so.6.0.30   [.] std::ostream::_M_insert<long>
        0,30%  main     [kernel.kallsyms]     [k] do_tty_write
        0,28%  main     libstdc++.so.6.0.30   [.] std::__ostream_insert<char, std::char_traits<char> >
---
perf record ./optimized perf report
---
        Samples: 2K of event 'cpu-clock:pppH', Event count (approx.): 723500000
        Overhead  Command    Shared Object         Symbol
        38,70%  optimized  [kernel.kallsyms]     [k] finish_task_switch.isra.0
        12,79%  optimized  libc.so.6             [.] __GI___libc_write
        4,70%  optimized  libc.so.6             [.] _IO_fwrite
        4,56%  optimized  [kernel.kallsyms]     [k] _raw_spin_unlock_irqrestore
        4,01%  optimized  [kernel.kallsyms]     [k] syscall_enter_from_user_mode
        3,32%  optimized  [kernel.kallsyms]     [k] process_output_block
        3,21%  optimized  optimized             [.] gcd
        1,52%  optimized  [kernel.kallsyms]     [k] pty_write
        1,35%  optimized  [kernel.kallsyms]     [k] n_tty_write
        1,35%  optimized  libc.so.6             [.] _IO_file_xsputn@@GLIBC_2.2.5
        1,07%  optimized  [kernel.kallsyms]     [k] __fget_light
        1,07%  optimized  [kernel.kallsyms]     [k] apparmor_file_permission
        1,07%  optimized  [kernel.kallsyms]     [k] file_tty_write.constprop.0
        1,00%  optimized  [kernel.kallsyms]     [k] queue_work_on
        1,00%  optimized  libstdc++.so.6.0.30   [.] std::ostream::sentry::sentry
        0,93%  optimized  [kernel.kallsyms]     [k] pty_write_room
        0,90%  optimized  libstdc++.so.6.0.30   [.] std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<long>
        0,86%  optimized  [kernel.kallsyms]     [k] vfs_write
        0,76%  optimized  [kernel.kallsyms]     [k] __check_heap_object
        0,73%  optimized  [vboxguest]           [k] vbg_req_perform
        0,73%  optimized  libstdc++.so.6.0.30   [.] std::ostream::_M_insert<long>
        0,55%  optimized  libstdc++.so.6.0.30   [.] std::ostream::put
        0,48%  optimized  [kernel.kallsyms]     [k] __virt_addr_valid
        0,48%  optimized  libc.so.6             [.] _IO_fflush
        0,48%  optimized  libstdc++.so.6.0.30   [.] std::__ostream_insert<char, std::char_traits<char> >
---