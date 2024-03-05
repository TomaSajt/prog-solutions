~ "../utils.ua" ~ NumsToString
UpperBound ← (
  ⊃(⊙∘|0|⧻)
  ⍢(
    ⊙⊙((:|+1⊙⋅∘))⊙::⊃(≥⊡:⊙:|⊙⊙∘)⊙⊙⊃(⌊÷2+|⊙∘)
  )(⋅⋅≠)
  ◌◌◌
)

InsertInto ← (⋅⊂|⍜⊡⋅∘)⊃(>⊙⧻|⊙∘)⊃(UpperBound:|:)
LIS ← ◌∧((⊙∘|.)⊃(≠∩⧻|⊙∘)InsertInto) ⊙[] ⊙[]

&fras "input.txt"
°□⊡1⊜□¬∊:"\n\r".

⊜⋕ ≠@\s.
↙ 20
.
⊃(¯LIS¯|LIS)

⊙⊗

# ∩(&p NumsToString)

# &fras "a.txt"
# ⊙◌°{⊙∘}⊜(□⊜⋕≠@\s.)¬∊:"\n\r".
# ⊗
