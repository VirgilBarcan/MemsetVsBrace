# MemsetVsBrace

## Benchmark
Running the benchmark (MemsetVsBraceBenchmark) should result in something like:

| Benchmark | Time | CPU | Iterations |
| --------- | ---- | --- | ---------- |
| BM_memset/8 | 225 ns | 227 ns | 3334003 |
| BM_memset/16 | 210 ns | 212 ns | 2856904 |
| BM_memset/32 | 204 ns | 206 ns | 3396287 |
| BM_memset/64 | 204 ns | 206 ns | 3378298 |
| BM_memset/128 | 204 ns | 206 ns | 3399498 |
| BM_memset/256 | 205 ns | 206 ns | 3393219 |
| BM_memset/512 | 202 ns | 203 ns | 3349546 |
| BM_memset/1024 | 202 ns | 203 ns | 3428820 |
| BM_memset/2048 | 202 ns | 203 ns | 3423083 |
| BM_memset/4096 | 202 ns | 204 ns | 3407031 |
| BM_memset/8192 | 211 ns | 213 ns | 3437737 |
| BM_braces/8 | 198 ns | 200 ns | 3510582 |
| BM_braces/16 | 197 ns | 200 ns | 3514881 |
| BM_braces/32 | 197 ns | 199 ns | 3459476 |
| BM_braces/64 | 199 ns | 202 ns | 3504713 |
| BM_braces/128 | 197 ns | 200 ns | 3509608 |
| BM_braces/256 | 197 ns | 199 ns | 3506707 |
| BM_braces/512 | 197 ns | 200 ns | 3500610 |
| BM_braces/1024 | 197 ns | 199 ns | 3507980 |
| BM_braces/2048 | 198 ns | 200 ns | 3504749 |
| BM_braces/4096 | 199 ns | 201 ns | 3516231 |
| BM_braces/8192 | 197 ns | 199 ns | 3519896 |


## Disassembly
Disassembling the other executable (MemsetVsBrace) gives something the following ASM code:
```assembly
0000000000400428 <_init>:
  400428:       48 83 ec 08             sub    $0x8,%rsp
  40042c:       48 8b 05 c5 0b 20 00    mov    0x200bc5(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  400433:       48 85 c0                test   %rax,%rax
  400436:       74 05                   je     40043d <_init+0x15>
  400438:       e8 53 00 00 00          callq  400490 <__libc_start_main@plt+0x10>
  40043d:       48 83 c4 08             add    $0x8,%rsp
  400441:       c3                      retq   

Disassembly of section .plt:

0000000000400450 <__stack_chk_fail@plt-0x10>:
  400450:       ff 35 b2 0b 20 00       pushq  0x200bb2(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400456:       ff 25 b4 0b 20 00       jmpq   *0x200bb4(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40045c:       0f 1f 40 00             nopl   0x0(%rax)

0000000000400460 <__stack_chk_fail@plt>:
  400460:       ff 25 b2 0b 20 00       jmpq   *0x200bb2(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400466:       68 00 00 00 00          pushq  $0x0
  40046b:       e9 e0 ff ff ff          jmpq   400450 <_init+0x28>

0000000000400470 <memset@plt>:
  400470:       ff 25 aa 0b 20 00       jmpq   *0x200baa(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400476:       68 01 00 00 00          pushq  $0x1
  40047b:       e9 d0 ff ff ff          jmpq   400450 <_init+0x28>

0000000000400480 <__libc_start_main@plt>:
  400480:       ff 25 a2 0b 20 00       jmpq   *0x200ba2(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400486:       68 02 00 00 00          pushq  $0x2
  40048b:       e9 c0 ff ff ff          jmpq   400450 <_init+0x28>

Disassembly of section .plt.got:

0000000000400490 <.plt.got>:
  400490:       ff 25 62 0b 20 00       jmpq   *0x200b62(%rip)        # 600ff8 <_DYNAMIC+0x1d0>
  400496:       66 90                   xchg   %ax,%ax

Disassembly of section .text:

00000000004004a0 <_start>:
  4004a0:       31 ed                   xor    %ebp,%ebp
  4004a2:       49 89 d1                mov    %rdx,%r9
  4004a5:       5e                      pop    %rsi
  4004a6:       48 89 e2                mov    %rsp,%rdx
  4004a9:       48 83 e4 f0             and    $0xfffffffffffffff0,%rsp
  4004ad:       50                      push   %rax
  4004ae:       54                      push   %rsp
  4004af:       49 c7 c0 80 06 40 00    mov    $0x400680,%r8
  4004b6:       48 c7 c1 10 06 40 00    mov    $0x400610,%rcx
  4004bd:       48 c7 c7 96 05 40 00    mov    $0x400596,%rdi
  4004c4:       e8 b7 ff ff ff          callq  400480 <__libc_start_main@plt>
  4004c9:       f4                      hlt    
  4004ca:       66 0f 1f 44 00 00       nopw   0x0(%rax,%rax,1)

00000000004004d0 <deregister_tm_clones>:
  4004d0:       b8 47 10 60 00          mov    $0x601047,%eax
  4004d5:       55                      push   %rbp
  4004d6:       48 2d 40 10 60 00       sub    $0x601040,%rax
  4004dc:       48 83 f8 0e             cmp    $0xe,%rax
  4004e0:       48 89 e5                mov    %rsp,%rbp
  4004e3:       76 1b                   jbe    400500 <deregister_tm_clones+0x30>
  4004e5:       b8 00 00 00 00          mov    $0x0,%eax
  4004ea:       48 85 c0                test   %rax,%rax
  4004ed:       74 11                   je     400500 <deregister_tm_clones+0x30>
  4004ef:       5d                      pop    %rbp
  4004f0:       bf 40 10 60 00          mov    $0x601040,%edi
  4004f5:       ff e0                   jmpq   *%rax
  4004f7:       66 0f 1f 84 00 00 00    nopw   0x0(%rax,%rax,1)
  4004fe:       00 00 
  400500:       5d                      pop    %rbp
  400501:       c3                      retq   
  400502:       0f 1f 40 00             nopl   0x0(%rax)
  400506:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
  40050d:       00 00 00 

0000000000400510 <register_tm_clones>:
  400510:       be 40 10 60 00          mov    $0x601040,%esi
  400515:       55                      push   %rbp
  400516:       48 81 ee 40 10 60 00    sub    $0x601040,%rsi
  40051d:       48 c1 fe 03             sar    $0x3,%rsi
  400521:       48 89 e5                mov    %rsp,%rbp
  400524:       48 89 f0                mov    %rsi,%rax
  400527:       48 c1 e8 3f             shr    $0x3f,%rax
  40052b:       48 01 c6                add    %rax,%rsi
  40052e:       48 d1 fe                sar    %rsi
  400531:       74 15                   je     400548 <register_tm_clones+0x38>
  400533:       b8 00 00 00 00          mov    $0x0,%eax
  400538:       48 85 c0                test   %rax,%rax
  40053b:       74 0b                   je     400548 <register_tm_clones+0x38>
  40053d:       5d                      pop    %rbp
  40053e:       bf 40 10 60 00          mov    $0x601040,%edi
  400543:       ff e0                   jmpq   *%rax
  400545:       0f 1f 00                nopl   (%rax)
  400548:       5d                      pop    %rbp
  400549:       c3                      retq   
  40054a:       66 0f 1f 44 00 00       nopw   0x0(%rax,%rax,1)

0000000000400550 <__do_global_dtors_aux>:
  400550:       80 3d e9 0a 20 00 00    cmpb   $0x0,0x200ae9(%rip)        # 601040 <__TMC_END__>
  400557:       75 11                   jne    40056a <__do_global_dtors_aux+0x1a>
  400559:       55                      push   %rbp
  40055a:       48 89 e5                mov    %rsp,%rbp
  40055d:       e8 6e ff ff ff          callq  4004d0 <deregister_tm_clones>
  400562:       5d                      pop    %rbp
  400563:       c6 05 d6 0a 20 00 01    movb   $0x1,0x200ad6(%rip)        # 601040 <__TMC_END__>
  40056a:       f3 c3                   repz retq 
  40056c:       0f 1f 40 00             nopl   0x0(%rax)

0000000000400570 <frame_dummy>:
  400570:       bf 20 0e 60 00          mov    $0x600e20,%edi
  400575:       48 83 3f 00             cmpq   $0x0,(%rdi)
  400579:       75 05                   jne    400580 <frame_dummy+0x10>
  40057b:       eb 93                   jmp    400510 <register_tm_clones>
  40057d:       0f 1f 00                nopl   (%rax)
  400580:       b8 00 00 00 00          mov    $0x0,%eax
  400585:       48 85 c0                test   %rax,%rax
  400588:       74 f1                   je     40057b <frame_dummy+0xb>
  40058a:       55                      push   %rbp
  40058b:       48 89 e5                mov    %rsp,%rbp
  40058e:       ff d0                   callq  *%rax
  400590:       5d                      pop    %rbp
  400591:       e9 7a ff ff ff          jmpq   400510 <register_tm_clones>

0000000000400596 <main>:
  400596:       55                      push   %rbp
  400597:       48 89 e5                mov    %rsp,%rbp
  40059a:       48 83 ec 60             sub    $0x60,%rsp
  40059e:       64 48 8b 04 25 28 00    mov    %fs:0x28,%rax
  4005a5:       00 00 
  4005a7:       48 89 45 f8             mov    %rax,-0x8(%rbp)
  4005ab:       31 c0                   xor    %eax,%eax
  4005ad:       48 c7 45 a0 00 00 00    movq   $0x0,-0x60(%rbp)
  4005b4:       00 
  4005b5:       48 c7 45 a8 00 00 00    movq   $0x0,-0x58(%rbp)
  4005bc:       00 
  4005bd:       48 c7 45 b0 00 00 00    movq   $0x0,-0x50(%rbp)
  4005c4:       00 
  4005c5:       48 c7 45 b8 00 00 00    movq   $0x0,-0x48(%rbp)
  4005cc:       00 
  4005cd:       48 c7 45 c0 00 00 00    movq   $0x0,-0x40(%rbp)
  4005d4:       00 
  4005d5:       48 8d 45 d0             lea    -0x30(%rbp),%rax
  4005d9:       ba 28 00 00 00          mov    $0x28,%edx
  4005de:       be 00 00 00 00          mov    $0x0,%esi
  4005e3:       48 89 c7                mov    %rax,%rdi
  4005e6:       e8 85 fe ff ff          callq  400470 <memset@plt>
  4005eb:       b8 00 00 00 00          mov    $0x0,%eax
  4005f0:       48 8b 4d f8             mov    -0x8(%rbp),%rcx
  4005f4:       64 48 33 0c 25 28 00    xor    %fs:0x28,%rcx
  4005fb:       00 00 
  4005fd:       74 05                   je     400604 <main+0x6e>
  4005ff:       e8 5c fe ff ff          callq  400460 <__stack_chk_fail@plt>
  400604:       c9                      leaveq 
  400605:       c3                      retq   
  400606:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
  40060d:       00 00 00 

0000000000400610 <__libc_csu_init>:
  400610:       41 57                   push   %r15
  400612:       41 56                   push   %r14
  400614:       41 89 ff                mov    %edi,%r15d
  400617:       41 55                   push   %r13
  400619:       41 54                   push   %r12
  40061b:       4c 8d 25 ee 07 20 00    lea    0x2007ee(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  400622:       55                      push   %rbp
  400623:       48 8d 2d ee 07 20 00    lea    0x2007ee(%rip),%rbp        # 600e18 <__init_array_end>
  40062a:       53                      push   %rbx
  40062b:       49 89 f6                mov    %rsi,%r14
  40062e:       49 89 d5                mov    %rdx,%r13
  400631:       4c 29 e5                sub    %r12,%rbp
  400634:       48 83 ec 08             sub    $0x8,%rsp
  400638:       48 c1 fd 03             sar    $0x3,%rbp
  40063c:       e8 e7 fd ff ff          callq  400428 <_init>
  400641:       48 85 ed                test   %rbp,%rbp
  400644:       74 20                   je     400666 <__libc_csu_init+0x56>
  400646:       31 db                   xor    %ebx,%ebx
  400648:       0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
  40064f:       00 
  400650:       4c 89 ea                mov    %r13,%rdx
  400653:       4c 89 f6                mov    %r14,%rsi
  400656:       44 89 ff                mov    %r15d,%edi
  400659:       41 ff 14 dc             callq  *(%r12,%rbx,8)
  40065d:       48 83 c3 01             add    $0x1,%rbx
  400661:       48 39 eb                cmp    %rbp,%rbx
  400664:       75 ea                   jne    400650 <__libc_csu_init+0x40>
  400666:       48 83 c4 08             add    $0x8,%rsp
  40066a:       5b                      pop    %rbx
  40066b:       5d                      pop    %rbp
  40066c:       41 5c                   pop    %r12
  40066e:       41 5d                   pop    %r13
  400670:       41 5e                   pop    %r14
  400672:       41 5f                   pop    %r15
  400674:       c3                      retq   
  400675:       90                      nop
  400676:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
  40067d:       00 00 00 

0000000000400680 <__libc_csu_fini>:
  400680:       f3 c3                   repz retq 

Disassembly of section .fini:

0000000000400684 <_fini>:
  400684:       48 83 ec 08             sub    $0x8,%rsp
  400688:       48 83 c4 08             add    $0x8,%rsp
  40068c:       c3                      retq 
```
Looking through the ASM code one can see that using braces leads to compile time *mov* instructions, while using a memset leads to a *lea* and a *call*, besides the other *mov*s. Memset brings another small overhead in terms of binary size (the size of its instructions).


## Info
Compilation of MemsetVsBrace: 
```zsh
gcc -std=c++11 memset_vs_brace.cpp -o MemsetVsBrace
```

Disassembly of MemsetVsBrace: 
```zsh
objdump -d MemsetVsBrace
```
