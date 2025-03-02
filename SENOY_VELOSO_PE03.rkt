#lang racket
; Programming Exercise 3
; Kyle Senoy and Justin Veloso C-1L

; (A) Function to compute factorial
(define (factorial n)
  (if (<= n 1)
      1  ; Base case: return 1 if n is 1 or less
      (* n (factorial (- n 1)))))  ; Recursive case

; User-Input (Factorial)
(displayln "(Factorial)")
(displayln "Input Size: ")
(define sizeA (read))
(displayln "Result: ")
(displayln (factorial sizeA))

; (B) Function to implement T-Ice sequence
(define (T-Ice n)
  (define (helper i result)
    (cond
      [(> i n) (reverse result)]  ; Reverse list before returning
      [(and (= (modulo i 2) 0) (= (modulo i 3) 0)) (helper (add1 i) (cons "T-ICE" result))]
      [(= (modulo i 2) 0) (helper (add1 i) (cons "T" result))]
      [(= (modulo i 3) 0) (helper (add1 i) (cons "ICE" result))]
      [else (helper (add1 i) (cons i result))]))
  (helper 1 '()))

; User-Input (T-Ice)
(displayln "(T-Ice)")
(displayln "Input Size: ")
(define sizeB (read))
(displayln "Result: ")
(displayln (T-Ice sizeB))

; (C) Function to perform arithmetic operations
(define (perform-op m n opt)
  (cond
    [(equal? opt '+) (+ m n)]
    [(equal? opt '-) (- m n)]
    [(equal? opt '*) (* m n)]
    [(equal? opt '/) (if (= n 0) "Error: Division by zero" (/ m n))]
    [(equal? opt '%) (if (= n 0) "Error: Modulo by zero" (modulo m n))]
    [else "Error: Invalid operator"]))

; User-Input (Perform operations)
(displayln "(Perform-op)")
(displayln "Input 1st Number: ")
(define num1 (read))
(displayln "Input 2nd Number: ")
(define num2 (read))
(displayln "Input Operator: ")
(define opt (read))
(displayln "Result: ")
(displayln (perform-op num1 num2 opt))

; (D) Function to calculate distance between two points
(define (calc-distance x1 x2 y1 y2)
  (sqrt (+ (sqr (abs (- x2 x1))) (sqr (abs (- y2 y1))))))

; User-Input (Calc-Distance)
(displayln "(Calc-distance)")
(displayln "Input x1: ")
(define x1 (read))
(displayln "Input y1: ")
(define y1 (read))
(displayln "Input x2: ")
(define x2 (read))
(displayln "Input y2: ")
(define y2 (read))
(displayln "Result: ")
(displayln (calc-distance x1 x2 y1 y2))

; (E) Function to count factors of m in n
(define (count-factors m n)
  (cond
    [(or (<= m 1) (<= n 0)) "Error: Invalid input, m must be > 1 and n must be > 0"]  ; Error handling for Invalid cases
    [(= n 1) 0]  ; Base case: Stop when n becomes 1
    [(zero? (remainder n m)) (+ 1 (count-factors m (/ n m)))]  ; If divisible, count and continue
    [else 0]))  ; If not a factor, return 0

; User-Input (Count factors)
(displayln "(Count-factors)")
(displayln "Enter n: ")
(define n (read))
(displayln "Enter m: ")
(define m (read))
(displayln "Result: ")
(let ((result (count-factors m n)))
  (displayln (if (equal? result 0) "None" result)))  ; Convert 0 to "None"
