~ "../utils.ua" ~ NumsToString

UpperBound ← (
  ⊃(⊙∘|0|⧻)
  ⍢(
    ⊙⊙((:|+1⊙⋅∘))⊙::⊃(≥⊡:⊙:|⊙⊙∘)⊙⊙⊃(⌊÷2+|⊙∘)
  )(⋅⋅≠)
  ◌◌◌
)

Add ← (
  ⍜∩⊟:
  ⊃(UpperBound ⊙⋅∘|⊙⊙∘)
  ⊃(⊙⊙⋅∘|⊙⋅⊙⋅∘|⍜⊡⋅∘⊙::(⊡-1|¯1)=0.⊙⋅⊙⋅∘)
  ∩((⋅⊂|⍜⊡⋅∘)⊃(>⊙⧻|⊙∘))
)

MakeLISIndices ← (
  ⊢⇌◌∧Add⟜(⊃(⇡|.[]|↯:∞)⧻)
  ◌◌⍢(⊃(⊡|⊙⊂:)|≠¯1) ⊙⊙[]
)

LIS ← ⊏MakeLISIndices.

&fras "input.txt"
°□⊡1⊜□¬∊:"\n\r".

⊜⋕ ≠@\s.

⊃(¯LIS¯|LIS)

∩(&pNumsToString)
