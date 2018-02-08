# MemsetVsBrace

Running it should result in something like:

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
