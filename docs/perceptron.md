
# Perceptron Algorithm

Given $n$ sample points $X_1, X_2, \dots, X_n$. Each sample point will have a label
$$ y_i = \begin{cases}
1 & \text{if } X_i \in C \\\
0 & \text{if } X_i \notin C
\end{cases}. $$
 For simplicity, the discussion will only consider decision boundaries that pass through the origin (for now).
**Goal:** Find weights $w$ such that,
$$ \begin{align*}
w \cdot X_i &\ge 0 \quad \text{if } y_i = 1 \\
w \cdot X_i &\le 0 \quad \text{if } y_i = -1
\end{align*} $$
Define *Loss Function*:
$$ L(\hat{y}, y_i) = \begin{cases}
0& \text{if } \hat{y} y_i \ge 0 \\
-y_i\hat{y}& \text{otherwise}
\end{cases} $$
Define *Cost Function*:
$$ \begin{align*}
R(w) &= \frac{1}{n} \sum_{i=1}^{n} L(X_i \cdot w, y_i) \\\
&= \frac{1}{n} \sum_{i \in V} -y_i X_i \cdot w
\end{align*} $$
where $V = \{i : y_iX_i \cdot < 0\}$. If $w$ classifies all $X_1, \dots, X_n$ correctly, then $R(w) = 0$. Othwerise, $R(w)$ is positive and we want to find another $w$ that minimizes $R$.

## Gradient Descent

Given a starting point $w$, compute $\nabla R(w)$ and take a "step" in the opposite direction that it points.
$$ \begin{align*}
\nabla R(w) &= \nabla \left(  \sum_{i \in V} -y_i X_i \cdot w \right) \\
&= -\sum_{i \in V} y_i X_i
\end{align*} $$
Roughly put at any $w$ we walk in the direction of $-\nabla R(w)$.
```
def gradientDescent(w) {
    initialize w;
    while R(w) > 0 {
        compute V = {i : y_i X_i * w < 0};
        w = w + eps * sum(y_i X_i for i in V);
    }
    return w;
}
```
## Stochastic Gradient Descent
Pseudocode:
```
stochasticGradientDescent(w) {
    @ each step X_i := missclassified;
    L(X_i * w, y_i) -> gradientDescent;
    while some y_i X_i * w < 0 {
        w = w + eps y_i X_i;
    }
    return w;
}
```