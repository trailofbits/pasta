# Token printing tests

These files represent testing for the token printing. The purpose of token
printing tests is to get token printing as close as possible to the original
parsed code, so as to minimize the amount of differences between the two. When
there are a lot of differences, we aren't able to use the provenance information
from the token printer to annotate the parsed tokens. When that happens, a new
test should be added and the printing or token alignment facilities fixed.