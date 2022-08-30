{⍵-⍨2×⍵*0.5}¨

⍝ if we have genetic equilibrium we know that
⍝ a = a^2 + ab + 0.25b^2
⍝ b = 0.5b^2 + 2ac + ab + bc
⍝ c = c^2 + bc + 0.25b^2
⍝ where a is dominant homozygous, b is heterozygous, c is recessive homozygous
⍝ we know c's value
⍝ from
⍝ c = c^2 + bc + 0.25b^2
⍝ we get
⍝ b = 2√c-2c
⍝ we are looking for b+c
⍝ b+c = 2√c-c
⍝ we have our solution