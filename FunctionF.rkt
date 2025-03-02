#lang racket
; Programming Exercise 3
; Kyle Senoy and Justin Veloso C-1L
; Function F - Count-factors of m in n

(define (count-factors m n)
  (cond
    [(= n 1) 0]  ; stop when n becomes 1
    [(zero? (remainder n m)) (+ 1 (count-factors m (/ n m)))]  ; count and continue dividing
    [else 0]))  ; if not a factor, return 0

(display "Enter n: ")
(define n (string->number (read-line)))
(display "Enter m: ")
(define m (string->number (read-line)))

(if (and (integer? n) (integer? m) (> m 1))
    (let ([result (count-factors m n)])
      (if (= result 0)
          (displayln "None")  ; Print "None" only if no factors exist
          (displayln result)))  ; Otherwise, print the count
    (displayln "Invalid input.")) 

