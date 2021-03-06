# model
model = Model()
i1 = Input("op1", "TENSOR_QUANT8_ASYMM", "{1, 2, 2, 1}, 0.5f, 5") # a vector of input
i2 = Input("op2", "TENSOR_QUANT8_ASYMM", "{1, 2, 2, 1}, 0.5f, 1") # a vector of alpha
i3 = Output("op3", "TENSOR_QUANT8_ASYMM", "{1, 2, 2, 1}, 0.1f, 3") # a vector of output
model = model.Operation("PRELU", i1, i2).To(i3)

# Example 1. Input in operand 0,
input0 = {i1: # input 0
          [3, 1,
           7, 11
	  ],
          i2: # input 1
          [0, 1,
	   2, 2]}

output0 = {i3: # output 0
           [8, 3,
            13, 33
           ]}
# Instantiate an example
Example((input0, output0))

