# Perceptron Algorithm

Given $n$ sample points $X_1, X_2, \dots, X_n$. Each sample point will have a label
\\[
y_i =
\begin{cases}
1 & \text{ if } X_i \in C \\
0 & \text{ if } X_i \notin C
\end{cases}
\\]
For simplicity, the discussion will only consider decision boundaries that pass 
through the origin (for now).

**Goal:** Find weights $w$ such that,
\\[
\begin{aligned}
w \cdot X_i &\ge 0 \text{ if } y_i = 1 \\
w \cdot X_i &\le 0 \text{ if } y_i = -1
\end{aligned}
\\]
To find the weight begin by defining what is called the __risk function__
$R(w)$, such that $R$ is positive if the constraints are violated. Then
perform an optimization technique that minimizes $R$.
