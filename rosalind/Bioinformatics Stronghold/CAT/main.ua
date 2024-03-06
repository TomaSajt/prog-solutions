~ "../utils.ua" ~ FASTA
MOD ← 1e6

Ways ← |1 memo(
  +⊃(≤0|≤1)⧻.
  (
    ⊏:"UAGC"⊗:"AUCG"°⊂
    ⊚⊃(=|⋅¤)
    ≡({⊙∘}⊃(↙|↘+1))

    ∧(◿MOD+)⊙0≡(◿MOD/×)∵(Ways °□)
  | 0
  | 1
  )
)

FASTA &fras "input.txt"
°□⊢⊙◌
Ways
