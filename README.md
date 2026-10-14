# 백준 알고리즘 문제 풀이

> [!NOTE]
> **보관용 저장소입니다.** 백준 온라인 저지 서비스가 종료되어 아래 문제 링크는 열리지 않을 수 있고, 이 저장소는 더 이상 업데이트하지 않습니다.

[백준 온라인 저지(BOJ)](https://www.acmicpc.net/) 문제를 C++로 풀고, 풀이에 쓴 핵심 기법별로 정리한 저장소입니다.

| 항목 | 내용 |
|---|---|
| 푼 문제 | 287문제 (풀이 파일 293개) |
| 분류 | 28개 |
| 언어 | C++ (UTF-8 · LF) |

## 폴더 구조와 이름 규칙

폴더는 풀이의 **핵심 기법(분류)**, 파일은 **문제 번호**입니다.

```text
dynamic-programming/
├── 1535.cpp                 ← <문제번호>.cpp
├── 2302.2025-04-14.cpp      ← 같은 문제를 다시 푼 풀이는 수정일을 붙여 구분
└── 2302.2026-04-20.cpp
```

- 분류는 solved.ac 같은 공식 알고리즘 태그가 아니라, 풀이에서 실제로 쓴 핵심 기법을 기준으로 나눴습니다. 공식 태그와 다를 수 있습니다.

## 컴파일 · 실행

풀이 293개 중 228개가 `#include <bits/stdc++.h>` 를 사용하므로 GCC(g++) 기준입니다.

```bash
g++ -std=c++17 -O2 -o /tmp/sol dynamic-programming/1535.cpp
/tmp/sol < input.txt
```

- 구조적 바인딩(`auto [a, b]`)을 쓰는 풀이가 있어 `-std=c++17` 이상이 필요합니다.
- `dynamic-programming/2618.cpp` 는 `scanf_s` / `printf_s` (MSVC 전용)를 사용해서 Visual Studio 에서만 컴파일됩니다.
- 컴파일 결과물과 `input.txt` · `output.txt` 같은 테스트용 파일은 `.gitignore` 로 제외됩니다.

## 분류별 풀이 수

| 분류 | 설명 | 풀이 파일 |
|---|---|--:|
| `dynamic-programming` | 동적 계획법 | 54 |
| `implementation` | 구현 · 시뮬레이션 | 41 |
| `bfs` | 너비 우선 탐색 | 32 |
| `dijkstra` | 다익스트라 (최단 경로) | 21 |
| `greedy` | 그리디 | 20 |
| `segment-tree` | 세그먼트 트리 · 펜윅 트리 | 14 |
| `brute-force` | 완전 탐색 | 12 |
| `data-structure` | 자료구조 (스택 · 큐 등) | 12 |
| `floyd-warshall` | 플로이드-워셜 | 10 |
| `string` | 문자열 | 10 |
| `two-pointer` | 투 포인터 | 8 |
| `binary-search` | 이분 탐색 | 7 |
| `math` | 수학 | 7 |
| `backtracking` | 백트래킹 | 6 |
| `dfs` | 깊이 우선 탐색 | 6 |
| `divide-and-conquer` | 분할 정복 | 6 |
| `recursion` | 재귀 | 4 |
| `tree` | 트리 | 4 |
| `union-find` | 유니온 파인드 | 4 |
| `graph-theory` | 그래프 이론 (벨만-포드 · 최대 유량 등) | 3 |
| `prefix-sum` | 누적 합 | 3 |
| `priority-queue` | 우선순위 큐 | 3 |
| `bipartite-matching` | 이분 매칭 | 1 |
| `lazy-propagation` | 느리게 갱신되는 세그먼트 트리 | 1 |
| `mos-algorithm` | 모 알고리즘 | 1 |
| `mst` | 최소 신장 트리 | 1 |
| `sorting` | 정렬 | 1 |
| `topological-sort` | 위상 정렬 | 1 |

## 문제 목록

문제 번호를 누르면 백준 문제 페이지로, 파일 이름을 누르면 풀이로 이동합니다.

<details>
<summary><b>동적 계획법</b> · <code>dynamic-programming</code> · 54개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1103](https://www.acmicpc.net/problem/1103) | [1103.cpp](dynamic-programming/1103.cpp) |
| [1315](https://www.acmicpc.net/problem/1315) | [1315.cpp](dynamic-programming/1315.cpp) |
| [1344](https://www.acmicpc.net/problem/1344) | [1344.cpp](dynamic-programming/1344.cpp) |
| [1351](https://www.acmicpc.net/problem/1351) | [1351.cpp](dynamic-programming/1351.cpp) |
| [1480](https://www.acmicpc.net/problem/1480) | [1480.cpp](dynamic-programming/1480.cpp) |
| [1509](https://www.acmicpc.net/problem/1509) | [1509.cpp](dynamic-programming/1509.cpp) |
| [1513](https://www.acmicpc.net/problem/1513) | [1513.cpp](dynamic-programming/1513.cpp) |
| [1514](https://www.acmicpc.net/problem/1514) | [1514.cpp](dynamic-programming/1514.cpp) |
| [1520](https://www.acmicpc.net/problem/1520) | [1520.cpp](dynamic-programming/1520.cpp) |
| [1535](https://www.acmicpc.net/problem/1535) | [1535.cpp](dynamic-programming/1535.cpp) |
| [1699](https://www.acmicpc.net/problem/1699) | [1699.cpp](dynamic-programming/1699.cpp) |
| [1788](https://www.acmicpc.net/problem/1788) | [1788.cpp](dynamic-programming/1788.cpp) |
| [1915](https://www.acmicpc.net/problem/1915) | [1915.cpp](dynamic-programming/1915.cpp) |
| [1937](https://www.acmicpc.net/problem/1937) | [1937.cpp](dynamic-programming/1937.cpp) |
| [1949](https://www.acmicpc.net/problem/1949) | [1949.cpp](dynamic-programming/1949.cpp) |
| [2011](https://www.acmicpc.net/problem/2011) | [2011.cpp](dynamic-programming/2011.cpp) |
| [2096](https://www.acmicpc.net/problem/2096) | [2096.cpp](dynamic-programming/2096.cpp) |
| [2098](https://www.acmicpc.net/problem/2098) | [2098.cpp](dynamic-programming/2098.cpp) |
| [2133](https://www.acmicpc.net/problem/2133) | [2133.cpp](dynamic-programming/2133.cpp) |
| [2240](https://www.acmicpc.net/problem/2240) | [2240.cpp](dynamic-programming/2240.cpp) |
| [2293](https://www.acmicpc.net/problem/2293) | [2293.cpp](dynamic-programming/2293.cpp) |
| [2294](https://www.acmicpc.net/problem/2294) | [2294.cpp](dynamic-programming/2294.cpp) |
| [2302](https://www.acmicpc.net/problem/2302) | [2025-04-14](dynamic-programming/2302.2025-04-14.cpp) · [2026-04-20](dynamic-programming/2302.2026-04-20.cpp) |
| [2342](https://www.acmicpc.net/problem/2342) | [2342.cpp](dynamic-programming/2342.cpp) |
| [2565](https://www.acmicpc.net/problem/2565) | [2565.cpp](dynamic-programming/2565.cpp) |
| [2618](https://www.acmicpc.net/problem/2618) | [2618.cpp](dynamic-programming/2618.cpp) |
| [2631](https://www.acmicpc.net/problem/2631) | [2631.cpp](dynamic-programming/2631.cpp) |
| [3687](https://www.acmicpc.net/problem/3687) | [3687.cpp](dynamic-programming/3687.cpp) |
| [4811](https://www.acmicpc.net/problem/4811) | [4811.cpp](dynamic-programming/4811.cpp) |
| [4883](https://www.acmicpc.net/problem/4883) | [4883.cpp](dynamic-programming/4883.cpp) |
| [9084](https://www.acmicpc.net/problem/9084) | [9084.cpp](dynamic-programming/9084.cpp) |
| [9252](https://www.acmicpc.net/problem/9252) | [9252.cpp](dynamic-programming/9252.cpp) |
| [9465](https://www.acmicpc.net/problem/9465) | [9465.cpp](dynamic-programming/9465.cpp) |
| [9665](https://www.acmicpc.net/problem/9665) | [9665.cpp](dynamic-programming/9665.cpp) |
| [10942](https://www.acmicpc.net/problem/10942) | [2025-05-25](dynamic-programming/10942.2025-05-25.cpp) · [2026-04-04](dynamic-programming/10942.2026-04-04.cpp) |
| [11049](https://www.acmicpc.net/problem/11049) | [11049.cpp](dynamic-programming/11049.cpp) |
| [11052](https://www.acmicpc.net/problem/11052) | [11052.cpp](dynamic-programming/11052.cpp) |
| [11057](https://www.acmicpc.net/problem/11057) | [11057.cpp](dynamic-programming/11057.cpp) |
| [11060](https://www.acmicpc.net/problem/11060) | [11060.cpp](dynamic-programming/11060.cpp) |
| 12582\* | [12582.cpp](dynamic-programming/12582.cpp) |
| [12784](https://www.acmicpc.net/problem/12784) | [12784.cpp](dynamic-programming/12784.cpp) |
| [14002](https://www.acmicpc.net/problem/14002) | [14002.cpp](dynamic-programming/14002.cpp) |
| [14003](https://www.acmicpc.net/problem/14003) | [14003.cpp](dynamic-programming/14003.cpp) |
| [14863](https://www.acmicpc.net/problem/14863) | [14863.cpp](dynamic-programming/14863.cpp) |
| [14916](https://www.acmicpc.net/problem/14916) | [14916.cpp](dynamic-programming/14916.cpp) |
| [15486](https://www.acmicpc.net/problem/15486) | [15486.cpp](dynamic-programming/15486.cpp) |
| [15988](https://www.acmicpc.net/problem/15988) | [15988.cpp](dynamic-programming/15988.cpp) |
| [16194](https://www.acmicpc.net/problem/16194) | [16194.cpp](dynamic-programming/16194.cpp) |
| [17258](https://www.acmicpc.net/problem/17258) | [17258.cpp](dynamic-programming/17258.cpp) |
| [17623](https://www.acmicpc.net/problem/17623) | [17623.cpp](dynamic-programming/17623.cpp) |
| [17626](https://www.acmicpc.net/problem/17626) | [17626.cpp](dynamic-programming/17626.cpp) |
| [25515](https://www.acmicpc.net/problem/25515) | [25515.cpp](dynamic-programming/25515.cpp) |

</details>

<details>
<summary><b>구현 · 시뮬레이션</b> · <code>implementation</code> · 41개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1064](https://www.acmicpc.net/problem/1064) | [1064.cpp](implementation/1064.cpp) |
| [2447](https://www.acmicpc.net/problem/2447) | [2447.cpp](implementation/2447.cpp) |
| [2828](https://www.acmicpc.net/problem/2828) | [2828.cpp](implementation/2828.cpp) |
| [2852](https://www.acmicpc.net/problem/2852) | [2852.cpp](implementation/2852.cpp) |
| [2979](https://www.acmicpc.net/problem/2979) | [2979.cpp](implementation/2979.cpp) |
| [3190](https://www.acmicpc.net/problem/3190) | [3190.cpp](implementation/3190.cpp) |
| [5373](https://www.acmicpc.net/problem/5373) | [5373.cpp](implementation/5373.cpp) |
| [10709](https://www.acmicpc.net/problem/10709) | [10709.cpp](implementation/10709.cpp) |
| [11723](https://www.acmicpc.net/problem/11723) | [2024-11-10](implementation/11723.2024-11-10.cpp) · [2026-03-12](implementation/11723.2026-03-12.cpp) |
| [13335](https://www.acmicpc.net/problem/13335) | [13335.cpp](implementation/13335.cpp) |
| [14500](https://www.acmicpc.net/problem/14500) | [14500.cpp](implementation/14500.cpp) |
| [14890](https://www.acmicpc.net/problem/14890) | [2025-09-03](implementation/14890.2025-09-03.cpp) · [2026-03-11](implementation/14890.2026-03-11.cpp) |
| [15312](https://www.acmicpc.net/problem/15312) | [15312.cpp](implementation/15312.cpp) |
| [15684](https://www.acmicpc.net/problem/15684) | [15684.cpp](implementation/15684.cpp) |
| [15685](https://www.acmicpc.net/problem/15685) | [15685.cpp](implementation/15685.cpp) |
| [16235](https://www.acmicpc.net/problem/16235) | [16235.cpp](implementation/16235.cpp) |
| [16236](https://www.acmicpc.net/problem/16236) | [16236.cpp](implementation/16236.cpp) |
| [16918](https://www.acmicpc.net/problem/16918) | [16918.cpp](implementation/16918.cpp) |
| [17140](https://www.acmicpc.net/problem/17140) | [17140.cpp](implementation/17140.cpp) |
| [17141](https://www.acmicpc.net/problem/17141) | [17141.cpp](implementation/17141.cpp) |
| [17142](https://www.acmicpc.net/problem/17142) | [17142.cpp](implementation/17142.cpp) |
| [17143](https://www.acmicpc.net/problem/17143) | [17143.cpp](implementation/17143.cpp) |
| [17144](https://www.acmicpc.net/problem/17144) | [17144.cpp](implementation/17144.cpp) |
| [17406](https://www.acmicpc.net/problem/17406) | [17406.cpp](implementation/17406.cpp) |
| [17779](https://www.acmicpc.net/problem/17779) | [17779.cpp](implementation/17779.cpp) |
| [17822](https://www.acmicpc.net/problem/17822) | [17822.cpp](implementation/17822.cpp) |
| [17825](https://www.acmicpc.net/problem/17825) | [17825.cpp](implementation/17825.cpp) |
| [17837](https://www.acmicpc.net/problem/17837) | [17837.cpp](implementation/17837.cpp) |
| [19236](https://www.acmicpc.net/problem/19236) | [19236.cpp](implementation/19236.cpp) |
| [19237](https://www.acmicpc.net/problem/19237) | [19237.cpp](implementation/19237.cpp) |
| [19238](https://www.acmicpc.net/problem/19238) | [19238.cpp](implementation/19238.cpp) |
| [20056](https://www.acmicpc.net/problem/20056) | [20056.cpp](implementation/20056.cpp) |
| [20057](https://www.acmicpc.net/problem/20057) | [20057.cpp](implementation/20057.cpp) |
| [20058](https://www.acmicpc.net/problem/20058) | [20058.cpp](implementation/20058.cpp) |
| [20061](https://www.acmicpc.net/problem/20061) | [20061.cpp](implementation/20061.cpp) |
| [21609](https://www.acmicpc.net/problem/21609) | [21609.cpp](implementation/21609.cpp) |
| [21611](https://www.acmicpc.net/problem/21611) | [21611.cpp](implementation/21611.cpp) |
| [23288](https://www.acmicpc.net/problem/23288) | [23288.cpp](implementation/23288.cpp) |
| [31218](https://www.acmicpc.net/problem/31218) | [31218.cpp](implementation/31218.cpp) |

</details>

<details>
<summary><b>너비 우선 탐색</b> · <code>bfs</code> · 32개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1012](https://www.acmicpc.net/problem/1012) | [1012.cpp](bfs/1012.cpp) |
| [1600](https://www.acmicpc.net/problem/1600) | [1600.cpp](bfs/1600.cpp) |
| [2146](https://www.acmicpc.net/problem/2146) | [2146.cpp](bfs/2146.cpp) |
| [2206](https://www.acmicpc.net/problem/2206) | [2206.cpp](bfs/2206.cpp) |
| [2210](https://www.acmicpc.net/problem/2210) | [2210.cpp](bfs/2210.cpp) |
| [2468](https://www.acmicpc.net/problem/2468) | [2468.cpp](bfs/2468.cpp) |
| [2573](https://www.acmicpc.net/problem/2573) | [2573.cpp](bfs/2573.cpp) |
| [2583](https://www.acmicpc.net/problem/2583) | [2583.cpp](bfs/2583.cpp) |
| [2589](https://www.acmicpc.net/problem/2589) | [2589.cpp](bfs/2589.cpp) |
| [2636](https://www.acmicpc.net/problem/2636) | [2636.cpp](bfs/2636.cpp) |
| [4179](https://www.acmicpc.net/problem/4179) | [4179.cpp](bfs/4179.cpp) |
| [5014](https://www.acmicpc.net/problem/5014) | [5014.cpp](bfs/5014.cpp) |
| [5427](https://www.acmicpc.net/problem/5427) | [5427.cpp](bfs/5427.cpp) |
| [6593](https://www.acmicpc.net/problem/6593) | [6593.cpp](bfs/6593.cpp) |
| [7562](https://www.acmicpc.net/problem/7562) | [7562.cpp](bfs/7562.cpp) |
| [7569](https://www.acmicpc.net/problem/7569) | [7569.cpp](bfs/7569.cpp) |
| [9328](https://www.acmicpc.net/problem/9328) | [9328.cpp](bfs/9328.cpp) |
| [11967](https://www.acmicpc.net/problem/11967) | [11967.cpp](bfs/11967.cpp) |
| [12869](https://www.acmicpc.net/problem/12869) | [12869.cpp](bfs/12869.cpp) |
| [12886](https://www.acmicpc.net/problem/12886) | [12886.cpp](bfs/12886.cpp) |
| [13913](https://www.acmicpc.net/problem/13913) | [13913.cpp](bfs/13913.cpp) |
| [14226](https://www.acmicpc.net/problem/14226) | [14226.cpp](bfs/14226.cpp) |
| [14442](https://www.acmicpc.net/problem/14442) | [14442.cpp](bfs/14442.cpp) |
| [14497](https://www.acmicpc.net/problem/14497) | [14497.cpp](bfs/14497.cpp) |
| [14502](https://www.acmicpc.net/problem/14502) | [14502.cpp](bfs/14502.cpp) |
| [14867](https://www.acmicpc.net/problem/14867) | [14867.cpp](bfs/14867.cpp) |
| [16920](https://www.acmicpc.net/problem/16920) | [16920.cpp](bfs/16920.cpp) |
| [16928](https://www.acmicpc.net/problem/16928) | [16928.cpp](bfs/16928.cpp) |
| [16933](https://www.acmicpc.net/problem/16933) | [16933.cpp](bfs/16933.cpp) |
| [16948](https://www.acmicpc.net/problem/16948) | [16948.cpp](bfs/16948.cpp) |
| [17071](https://www.acmicpc.net/problem/17071) | [17071.cpp](bfs/17071.cpp) |
| [17616](https://www.acmicpc.net/problem/17616) | [17616.cpp](bfs/17616.cpp) |

</details>

<details>
<summary><b>다익스트라 (최단 경로)</b> · <code>dijkstra</code> · 21개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1162](https://www.acmicpc.net/problem/1162) | [1162.cpp](dijkstra/1162.cpp) |
| [1446](https://www.acmicpc.net/problem/1446) | [1446.cpp](dijkstra/1446.cpp) |
| [1602](https://www.acmicpc.net/problem/1602) | [1602.cpp](dijkstra/1602.cpp) |
| [1854](https://www.acmicpc.net/problem/1854) | [1854.cpp](dijkstra/1854.cpp) |
| [2316](https://www.acmicpc.net/problem/2316) | [2316.cpp](dijkstra/2316.cpp) |
| [4485](https://www.acmicpc.net/problem/4485) | [4485.cpp](dijkstra/4485.cpp) |
| [5719](https://www.acmicpc.net/problem/5719) | [2024-09-23](dijkstra/5719.2024-09-23.cpp) · [2026-04-05](dijkstra/5719.2026-04-05.cpp) |
| [5972](https://www.acmicpc.net/problem/5972) | [5972.cpp](dijkstra/5972.cpp) |
| [9370](https://www.acmicpc.net/problem/9370) | [9370.cpp](dijkstra/9370.cpp) |
| [10217](https://www.acmicpc.net/problem/10217) | [10217.cpp](dijkstra/10217.cpp) |
| [10282](https://www.acmicpc.net/problem/10282) | [10282.cpp](dijkstra/10282.cpp) |
| [11779](https://www.acmicpc.net/problem/11779) | [11779.cpp](dijkstra/11779.cpp) |
| [13549](https://www.acmicpc.net/problem/13549) | [13549.cpp](dijkstra/13549.cpp) |
| [13907](https://www.acmicpc.net/problem/13907) | [13907.cpp](dijkstra/13907.cpp) |
| [15972](https://www.acmicpc.net/problem/15972) | [15972.cpp](dijkstra/15972.cpp) |
| [16118](https://www.acmicpc.net/problem/16118) | [16118.cpp](dijkstra/16118.cpp) |
| [17835](https://www.acmicpc.net/problem/17835) | [17835.cpp](dijkstra/17835.cpp) |
| [20183](https://www.acmicpc.net/problem/20183) | [20183.cpp](dijkstra/20183.cpp) |
| [22870](https://www.acmicpc.net/problem/22870) | [22870.cpp](dijkstra/22870.cpp) |
| [24042](https://www.acmicpc.net/problem/24042) | [24042.cpp](dijkstra/24042.cpp) |

</details>

<details>
<summary><b>그리디</b> · <code>greedy</code> · 20개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1049](https://www.acmicpc.net/problem/1049) | [1049.cpp](greedy/1049.cpp) |
| [1339](https://www.acmicpc.net/problem/1339) | [1339.cpp](greedy/1339.cpp) |
| [1700](https://www.acmicpc.net/problem/1700) | [1700.cpp](greedy/1700.cpp) |
| [1744](https://www.acmicpc.net/problem/1744) | [1744.cpp](greedy/1744.cpp) |
| [1911](https://www.acmicpc.net/problem/1911) | [1911.cpp](greedy/1911.cpp) |
| [1931](https://www.acmicpc.net/problem/1931) | [1931.cpp](greedy/1931.cpp) |
| [2109](https://www.acmicpc.net/problem/2109) | [2109.cpp](greedy/2109.cpp) |
| [2170](https://www.acmicpc.net/problem/2170) | [2170.cpp](greedy/2170.cpp) |
| [2217](https://www.acmicpc.net/problem/2217) | [2217.cpp](greedy/2217.cpp) |
| [2457](https://www.acmicpc.net/problem/2457) | [2457.cpp](greedy/2457.cpp) |
| [2812](https://www.acmicpc.net/problem/2812) | [2812.cpp](greedy/2812.cpp) |
| [3109](https://www.acmicpc.net/problem/3109) | [3109.cpp](greedy/3109.cpp) |
| [7570](https://www.acmicpc.net/problem/7570) | [7570.cpp](greedy/7570.cpp) |
| [8890](https://www.acmicpc.net/problem/8890) | [8890.cpp](greedy/8890.cpp) |
| [11000](https://www.acmicpc.net/problem/11000) | [11000.cpp](greedy/11000.cpp) |
| [11047](https://www.acmicpc.net/problem/11047) | [11047.cpp](greedy/11047.cpp) |
| [12904](https://www.acmicpc.net/problem/12904) | [12904.cpp](greedy/12904.cpp) |
| [12970](https://www.acmicpc.net/problem/12970) | [12970.cpp](greedy/12970.cpp) |
| [15903](https://www.acmicpc.net/problem/15903) | [15903.cpp](greedy/15903.cpp) |
| [18234](https://www.acmicpc.net/problem/18234) | [18234.cpp](greedy/18234.cpp) |

</details>

<details>
<summary><b>세그먼트 트리 · 펜윅 트리</b> · <code>segment-tree</code> · 14개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1275](https://www.acmicpc.net/problem/1275) | [1275.cpp](segment-tree/1275.cpp) |
| [1280](https://www.acmicpc.net/problem/1280) | [1280.cpp](segment-tree/1280.cpp) |
| [1395](https://www.acmicpc.net/problem/1395) | [1395.cpp](segment-tree/1395.cpp) |
| [2104](https://www.acmicpc.net/problem/2104) | [2104.cpp](segment-tree/2104.cpp) |
| [2243](https://www.acmicpc.net/problem/2243) | [2243.cpp](segment-tree/2243.cpp) |
| [3653](https://www.acmicpc.net/problem/3653) | [3653.cpp](segment-tree/3653.cpp) |
| [5419](https://www.acmicpc.net/problem/5419) | [5419.cpp](segment-tree/5419.cpp) |
| [6213](https://www.acmicpc.net/problem/6213) | [6213.cpp](segment-tree/6213.cpp) |
| [11505](https://www.acmicpc.net/problem/11505) | [11505.cpp](segment-tree/11505.cpp) |
| [11658](https://www.acmicpc.net/problem/11658) | [2025-08-06](segment-tree/11658.2025-08-06.cpp) · [2026-04-20](segment-tree/11658.2026-04-20.cpp) |
| [12837](https://www.acmicpc.net/problem/12837) | [12837.cpp](segment-tree/12837.cpp) |
| [14427](https://www.acmicpc.net/problem/14427) | [14427.cpp](segment-tree/14427.cpp) |
| [18436](https://www.acmicpc.net/problem/18436) | [18436.cpp](segment-tree/18436.cpp) |

</details>

<details>
<summary><b>완전 탐색</b> · <code>brute-force</code> · 12개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1027](https://www.acmicpc.net/problem/1027) | [1027.cpp](brute-force/1027.cpp) |
| [1062](https://www.acmicpc.net/problem/1062) | [1062.cpp](brute-force/1062.cpp) |
| [1107](https://www.acmicpc.net/problem/1107) | [1107.cpp](brute-force/1107.cpp) |
| [1285](https://www.acmicpc.net/problem/1285) | [1285.cpp](brute-force/1285.cpp) |
| [1450](https://www.acmicpc.net/problem/1450) | [1450.cpp](brute-force/1450.cpp) |
| [1940](https://www.acmicpc.net/problem/1940) | [1940.cpp](brute-force/1940.cpp) |
| [6064](https://www.acmicpc.net/problem/6064) | [6064.cpp](brute-force/6064.cpp) |
| [9663](https://www.acmicpc.net/problem/9663) | [9663.cpp](brute-force/9663.cpp) |
| [14391](https://www.acmicpc.net/problem/14391) | [14391.cpp](brute-force/14391.cpp) |
| [16637](https://www.acmicpc.net/problem/16637) | [16637.cpp](brute-force/16637.cpp) |
| [17471](https://www.acmicpc.net/problem/17471) | [17471.cpp](brute-force/17471.cpp) |
| [19942](https://www.acmicpc.net/problem/19942) | [19942.cpp](brute-force/19942.cpp) |

</details>

<details>
<summary><b>자료구조 (스택 · 큐 등)</b> · <code>data-structure</code> · 12개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1620](https://www.acmicpc.net/problem/1620) | [1620.cpp](data-structure/1620.cpp) |
| [1874](https://www.acmicpc.net/problem/1874) | [1874.cpp](data-structure/1874.cpp) |
| [2493](https://www.acmicpc.net/problem/2493) | [2493.cpp](data-structure/2493.cpp) |
| [2504](https://www.acmicpc.net/problem/2504) | [2504.cpp](data-structure/2504.cpp) |
| [2531](https://www.acmicpc.net/problem/2531) | [2531.cpp](data-structure/2531.cpp) |
| [3015](https://www.acmicpc.net/problem/3015) | [3015.cpp](data-structure/3015.cpp) |
| [3986](https://www.acmicpc.net/problem/3986) | [3986.cpp](data-structure/3986.cpp) |
| [4949](https://www.acmicpc.net/problem/4949) | [4949.cpp](data-structure/4949.cpp) |
| [6198](https://www.acmicpc.net/problem/6198) | [6198.cpp](data-structure/6198.cpp) |
| [10799](https://www.acmicpc.net/problem/10799) | [10799.cpp](data-structure/10799.cpp) |
| [15926](https://www.acmicpc.net/problem/15926) | [15926.cpp](data-structure/15926.cpp) |
| [17298](https://www.acmicpc.net/problem/17298) | [17298.cpp](data-structure/17298.cpp) |

</details>

<details>
<summary><b>플로이드-워셜</b> · <code>floyd-warshall</code> · 10개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1486](https://www.acmicpc.net/problem/1486) | [1486.cpp](floyd-warshall/1486.cpp) |
| [1507](https://www.acmicpc.net/problem/1507) | [1507.cpp](floyd-warshall/1507.cpp) |
| [1613](https://www.acmicpc.net/problem/1613) | [1613.cpp](floyd-warshall/1613.cpp) |
| [1956](https://www.acmicpc.net/problem/1956) | [1956.cpp](floyd-warshall/1956.cpp) |
| [11780](https://www.acmicpc.net/problem/11780) | [11780.cpp](floyd-warshall/11780.cpp) |
| [13141](https://www.acmicpc.net/problem/13141) | [13141.cpp](floyd-warshall/13141.cpp) |
| [14938](https://www.acmicpc.net/problem/14938) | [14938.cpp](floyd-warshall/14938.cpp) |
| [17182](https://www.acmicpc.net/problem/17182) | [17182.cpp](floyd-warshall/17182.cpp) |
| [21940](https://www.acmicpc.net/problem/21940) | [21940.cpp](floyd-warshall/21940.cpp) |
| [23258](https://www.acmicpc.net/problem/23258) | [23258.cpp](floyd-warshall/23258.cpp) |

</details>

<details>
<summary><b>문자열</b> · <code>string</code> · 10개</summary>

| 문제 | 풀이 |
|:-:|---|
| [2870](https://www.acmicpc.net/problem/2870) | [2870.cpp](string/2870.cpp) |
| [2941](https://www.acmicpc.net/problem/2941) | [2941.cpp](string/2941.cpp) |
| [2999](https://www.acmicpc.net/problem/2999) | [2999.cpp](string/2999.cpp) |
| [4659](https://www.acmicpc.net/problem/4659) | [4659.cpp](string/4659.cpp) |
| [9536](https://www.acmicpc.net/problem/9536) | [9536.cpp](string/9536.cpp) |
| [9935](https://www.acmicpc.net/problem/9935) | [9935.cpp](string/9935.cpp) |
| [14405](https://www.acmicpc.net/problem/14405) | [14405.cpp](string/14405.cpp) |
| [16172](https://www.acmicpc.net/problem/16172) | [16172.cpp](string/16172.cpp) |
| [16916](https://www.acmicpc.net/problem/16916) | [16916.cpp](string/16916.cpp) |
| [17413](https://www.acmicpc.net/problem/17413) | [17413.cpp](string/17413.cpp) |

</details>

<details>
<summary><b>투 포인터</b> · <code>two-pointer</code> · 8개</summary>

| 문제 | 풀이 |
|:-:|---|
| [2003](https://www.acmicpc.net/problem/2003) | [2003.cpp](two-pointer/2003.cpp) |
| [2230](https://www.acmicpc.net/problem/2230) | [2230.cpp](two-pointer/2230.cpp) |
| [2470](https://www.acmicpc.net/problem/2470) | [2470.cpp](two-pointer/2470.cpp) |
| [13144](https://www.acmicpc.net/problem/13144) | [13144.cpp](two-pointer/13144.cpp) |
| [13422](https://www.acmicpc.net/problem/13422) | [13422.cpp](two-pointer/13422.cpp) |
| [20922](https://www.acmicpc.net/problem/20922) | [20922.cpp](two-pointer/20922.cpp) |
| [22862](https://www.acmicpc.net/problem/22862) | [22862.cpp](two-pointer/22862.cpp) |
| [30804](https://www.acmicpc.net/problem/30804) | [30804.cpp](two-pointer/30804.cpp) |

</details>

<details>
<summary><b>이분 탐색</b> · <code>binary-search</code> · 7개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1561](https://www.acmicpc.net/problem/1561) | [1561.cpp](binary-search/1561.cpp) |
| [1654](https://www.acmicpc.net/problem/1654) | [1654.cpp](binary-search/1654.cpp) |
| 2276\* | [2276.cpp](binary-search/2276.cpp) |
| [2343](https://www.acmicpc.net/problem/2343) | [2343.cpp](binary-search/2343.cpp) |
| [2792](https://www.acmicpc.net/problem/2792) | [2792.cpp](binary-search/2792.cpp) |
| [2805](https://www.acmicpc.net/problem/2805) | [2805.cpp](binary-search/2805.cpp) |
| [16434](https://www.acmicpc.net/problem/16434) | [16434.cpp](binary-search/16434.cpp) |

</details>

<details>
<summary><b>수학</b> · <code>math</code> · 7개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1094](https://www.acmicpc.net/problem/1094) | [1094.cpp](math/1094.cpp) |
| [1292](https://www.acmicpc.net/problem/1292) | [1292.cpp](math/1292.cpp) |
| [1644](https://www.acmicpc.net/problem/1644) | [1644.cpp](math/1644.cpp) |
| [2960](https://www.acmicpc.net/problem/2960) | [2960.cpp](math/2960.cpp) |
| [3474](https://www.acmicpc.net/problem/3474) | [3474.cpp](math/3474.cpp) |
| [14864](https://www.acmicpc.net/problem/14864) | [14864.cpp](math/14864.cpp) |
| [15353](https://www.acmicpc.net/problem/15353) | [15353.cpp](math/15353.cpp) |

</details>

<details>
<summary><b>백트래킹</b> · <code>backtracking</code> · 6개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1189](https://www.acmicpc.net/problem/1189) | [1189.cpp](backtracking/1189.cpp) |
| [1941](https://www.acmicpc.net/problem/1941) | [1941.cpp](backtracking/1941.cpp) |
| [14620](https://www.acmicpc.net/problem/14620) | [14620.cpp](backtracking/14620.cpp) |
| [16987](https://www.acmicpc.net/problem/16987) | [16987.cpp](backtracking/16987.cpp) |
| [17136](https://www.acmicpc.net/problem/17136) | [17136.cpp](backtracking/17136.cpp) |
| [18809](https://www.acmicpc.net/problem/18809) | [18809.cpp](backtracking/18809.cpp) |

</details>

<details>
<summary><b>깊이 우선 탐색</b> · <code>dfs</code> · 6개</summary>

| 문제 | 풀이 |
|:-:|---|
| [2234](https://www.acmicpc.net/problem/2234) | [2234.cpp](dfs/2234.cpp) |
| [2617](https://www.acmicpc.net/problem/2617) | [2617.cpp](dfs/2617.cpp) |
| [4963](https://www.acmicpc.net/problem/4963) | [4963.cpp](dfs/4963.cpp) |
| [9466](https://www.acmicpc.net/problem/9466) | [9466.cpp](dfs/9466.cpp) |
| [10026](https://www.acmicpc.net/problem/10026) | [10026.cpp](dfs/10026.cpp) |
| [13244](https://www.acmicpc.net/problem/13244) | [13244.cpp](dfs/13244.cpp) |

</details>

<details>
<summary><b>분할 정복</b> · <code>divide-and-conquer</code> · 6개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1780](https://www.acmicpc.net/problem/1780) | [1780.cpp](divide-and-conquer/1780.cpp) |
| [1992](https://www.acmicpc.net/problem/1992) | [1992.cpp](divide-and-conquer/1992.cpp) |
| [2580](https://www.acmicpc.net/problem/2580) | [2580.cpp](divide-and-conquer/2580.cpp) |
| [2630](https://www.acmicpc.net/problem/2630) | [2630.cpp](divide-and-conquer/2630.cpp) |
| [10830](https://www.acmicpc.net/problem/10830) | [10830.cpp](divide-and-conquer/10830.cpp) |
| [11444](https://www.acmicpc.net/problem/11444) | [11444.cpp](divide-and-conquer/11444.cpp) |

</details>

<details>
<summary><b>재귀</b> · <code>recursion</code> · 4개</summary>

| 문제 | 풀이 |
|:-:|---|
| [2448](https://www.acmicpc.net/problem/2448) | [2448.cpp](recursion/2448.cpp) |
| [14956](https://www.acmicpc.net/problem/14956) | [14956.cpp](recursion/14956.cpp) |
| [17297](https://www.acmicpc.net/problem/17297) | [17297.cpp](recursion/17297.cpp) |
| [17478](https://www.acmicpc.net/problem/17478) | [17478.cpp](recursion/17478.cpp) |

</details>

<details>
<summary><b>트리</b> · <code>tree</code> · 4개</summary>

| 문제 | 풀이 |
|:-:|---|
| [4256](https://www.acmicpc.net/problem/4256) | [4256.cpp](tree/4256.cpp) |
| [9489](https://www.acmicpc.net/problem/9489) | [9489.cpp](tree/9489.cpp) |
| [9934](https://www.acmicpc.net/problem/9934) | [9934.cpp](tree/9934.cpp) |
| [11438](https://www.acmicpc.net/problem/11438) | [11438.cpp](tree/11438.cpp) |

</details>

<details>
<summary><b>유니온 파인드</b> · <code>union-find</code> · 4개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1043](https://www.acmicpc.net/problem/1043) | [1043.cpp](union-find/1043.cpp) |
| [1976](https://www.acmicpc.net/problem/1976) | [1976.cpp](union-find/1976.cpp) |
| [18116](https://www.acmicpc.net/problem/18116) | [18116.cpp](union-find/18116.cpp) |
| [20040](https://www.acmicpc.net/problem/20040) | [20040.cpp](union-find/20040.cpp) |

</details>

<details>
<summary><b>그래프 이론 (벨만-포드 · 최대 유량 등)</b> · <code>graph-theory</code> · 3개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1219](https://www.acmicpc.net/problem/1219) | [1219.cpp](graph-theory/1219.cpp) |
| [6086](https://www.acmicpc.net/problem/6086) | [6086.cpp](graph-theory/6086.cpp) |
| [10451](https://www.acmicpc.net/problem/10451) | [10451.cpp](graph-theory/10451.cpp) |

</details>

<details>
<summary><b>누적 합</b> · <code>prefix-sum</code> · 3개</summary>

| 문제 | 풀이 |
|:-:|---|
| [2632](https://www.acmicpc.net/problem/2632) | [2632.cpp](prefix-sum/2632.cpp) |
| [17611](https://www.acmicpc.net/problem/17611) | [17611.cpp](prefix-sum/17611.cpp) |
| [25682](https://www.acmicpc.net/problem/25682) | [25682.cpp](prefix-sum/25682.cpp) |

</details>

<details>
<summary><b>우선순위 큐</b> · <code>priority-queue</code> · 3개</summary>

| 문제 | 풀이 |
|:-:|---|
| [2696](https://www.acmicpc.net/problem/2696) | [2696.cpp](priority-queue/2696.cpp) |
| 11279\* | [11279.cpp](priority-queue/11279.cpp) |
| [17612](https://www.acmicpc.net/problem/17612) | [17612.cpp](priority-queue/17612.cpp) |

</details>

<details>
<summary><b>이분 매칭</b> · <code>bipartite-matching</code> · 1개</summary>

| 문제 | 풀이 |
|:-:|---|
| [1799](https://www.acmicpc.net/problem/1799) | [1799.cpp](bipartite-matching/1799.cpp) |

</details>

<details>
<summary><b>느리게 갱신되는 세그먼트 트리</b> · <code>lazy-propagation</code> · 1개</summary>

| 문제 | 풀이 |
|:-:|---|
| [16975](https://www.acmicpc.net/problem/16975) | [16975.cpp](lazy-propagation/16975.cpp) |

</details>

<details>
<summary><b>모 알고리즘</b> · <code>mos-algorithm</code> · 1개</summary>

| 문제 | 풀이 |
|:-:|---|
| [13547](https://www.acmicpc.net/problem/13547) | [13547.cpp](mos-algorithm/13547.cpp) |

</details>

<details>
<summary><b>최소 신장 트리</b> · <code>mst</code> · 1개</summary>

| 문제 | 풀이 |
|:-:|---|
| [11657](https://www.acmicpc.net/problem/11657) | [11657.cpp](mst/11657.cpp) |

</details>

<details>
<summary><b>정렬</b> · <code>sorting</code> · 1개</summary>

| 문제 | 풀이 |
|:-:|---|
| [18870](https://www.acmicpc.net/problem/18870) | [18870.cpp](sorting/18870.cpp) |

</details>

<details>
<summary><b>위상 정렬</b> · <code>topological-sort</code> · 1개</summary>

| 문제 | 풀이 |
|:-:|---|
| [3665](https://www.acmicpc.net/problem/3665) | [3665.cpp](topological-sort/3665.cpp) |

</details>

\* 파일 번호와 코드가 푸는 문제가 달라 보여 백준 링크를 달지 않았습니다. 코드로 보아 `2276.cpp` 는 2776번(암기왕), `11279.cpp` 는 1927번(최소 힙), `12582.cpp` 는 12852번(1로 만들기 2)에 가까워 보이지만, 서비스 종료로 확인하지 못했습니다.
