def read_data_from_file(fname = "hello_u8bit_amplified.raw"):
    f = open(fname, 'rb')
    raw_data = [ord(val) for val in f.read()]
    return f, raw_data

def get_

def compress_data(raw_data):
    count = 1
    last_byte = 0
    comp_data = []
    cur_val = raw_data[0]
    for idx, val in enumerate(raw_data):
        if val == cur_val :
            count += 1
        else:
            comp_data.append((cur_val, count))
            cur_val = val
            count = 1

    return comp_data
        
