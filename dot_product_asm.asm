section .text
bits 64
default rel
global dot_product_asm


; float dot_product_asm(float* A, float* B, int n)
; RCX = A, RDX = B, R8D = n

dot_product_asm:
    push rbp
    mov rbp, rsp
    push rbx                    

    ; RCX = A, RDX = B, R8D = n
    mov rax, rcx                
    mov rbx, rdx                
    mov ecx, r8d                

    xor edx, edx                
    xorps xmm0, xmm0            

loop:
    cmp edx, ecx
    jge done

    ; xmm1 = A[i], xmm2 = B[i]
    movss xmm1, [rax + rdx*4]
    movss xmm2, [rbx + rdx*4]
    mulss xmm1, xmm2
    addss xmm0, xmm1

    inc edx
    jmp loop

done:
    pop rbx
    pop rbp
    ret
