extern ExitProcess ; Déclaration de la fonction Windows pour mettre fin au processus.
global Start       ; Déclaration de la fonction principale du programme.

section .text      ; Section de code du programme.
Start:             ; Point d'entré du programme.
                   ; Code source du programme.
xor rax, rax ; Ligne 1
  push rax     ; Ligne 2

  mov ah, 125  ; Ligne 3
  mov al, 135  ; Ligne 4
  add ah, al   ; Ligne 5

  mov rbx, 2   ; Ligne 6
  mov rcx, 4   ; Ligne 7
  call Swap    ; Ligne 8

  pop rdx      ; Ligne 9

  ; Point de sortie du programme
call ExitProcess ; Appel du système d'exploitation.
Swap:          ; Ligne 10
  push rbx     ; Ligne 11
  push rcx     ; Ligne 12
  pop rbx      ; Ligne 13
  pop rcx      ; Ligne 14

  ret          ; Ligne 15

