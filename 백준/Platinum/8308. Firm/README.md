# [Platinum II] Firm - 8308 

[문제 링크](https://www.acmicpc.net/problem/8308) 

### 성능 요약

메모리: 37844 KB, 시간: 112 ms

### 분류

자료 구조, 트리, 세그먼트 트리, 이분 탐색, 집합과 맵, 트리를 사용한 집합과 맵, 오프라인 쿼리, 오일러 경로 테크닉

### 제출 일자

2025년 12월 15일 12:22:39

### 문제 설명

<p>In a fast developing firm, new employees are often hired. Each new employee p is assigned a direct superior, whose superiors (both direct and indirect) become indirect superiors of p.</p>

<p>We call the direct superior of p a superior of <em>degree</em> 0. The superior of a superior of degree 0 has a degree equal to 1. In general, a superior of a superior of degree k has degree k+1. In this way, an employee is a subordinate of his immediate superior and superiors of higher degree. This defines a hierarchy of all employees, which has the founder of the company on its top.</p>

<p>The history of all employees who have joined the company since the foundation is recorded. Some employees wonder for how many subordinates they are superiors of degree k. Would you mind writing a program, which will assist them in solving this problem, so that they could go back to work?</p>

### 입력 

 <p>In the first line of the standard input there is an integer n (1 ≤ n ≤ 10<sup>5</sup>), denoting the number of events. The following n lines contain descriptions of the events, one per line, given in chronological order.</p>

<p>An event of hiring a new employee is described by a character '<code>Z</code>' and two integers p<sub>i</sub> and s<sub>i</sub> (2 ≤ p<sub>i</sub> ≤ 10<sup>5</sup>, p<sub>i</sub> ≠ p<sub>j</sub> for i ≠ j), which represent the numbers of the new employee and his immediate superior, respectively. s<sub>i</sub> is equal to the number of some employee, who is currently hired. The founder is assigned number 1.</p>

<p>A question from an employee q<sub>i</sub> about the number of his subordinates, for whom he is a superior of degree k<sub>i</sub>, is described by a character '<code>P</code>' and two integers q<sub>i</sub> and k<sub>i</sub> (1 ≤ q<sub>i</sub> ≤ 10<sup>5</sup>, 0 ≤ k<sub>i</sub> ≤ 10<sup>5</sup>).</p>

<p>Before the first event the founder was the only person working in the firm.</p>

### 출력 

 <p>For each question from an employee output one line to the standard output with one integer equal to the number of subordinates of this employee, for whom he is a superior of degree k<sub>i</sub>.</p>

