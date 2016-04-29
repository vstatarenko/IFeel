#! -*- coding: utf-8 -*-
import sys

# param_name: required
PARAMS = {
    '--integer': True,
    '--boolean': True,
    '--string': False,
}


def param_value_or_none(param_name):
    for arg in sys.argv:
        if param_name in arg:
            return arg.split('=')[1]

    return None


def generate_help_message(file_name):
    msg = ''
    for param_name, required in PARAMS.items():
        if not required:
            param_name = '[{}] '.format(param_name)
        msg += param_name + ' '
    msg = 'Use: {fname} {rest_msg}'.format(fname=file_name, rest_msg=msg)
    return msg


def getopt():
    """
    returns dict with parsed params
    """
    passed = []
    file_name = sys.argv[0]

    # if script called without params or 'help' was found in one of params
    if len(sys.argv) == 1 or True in ['help' in arg for arg in sys.argv]:
        return generate_help_message(file_name)

    for param_name, required in PARAMS.items():
        value = param_value_or_none(param_name)

        if required:
            if value is None:
                # returns warning about required value
                return ' '.join([param_name, 'required'])
            passed.append({param_name: value})
        else:
            passed.append({param_name: value})

    return passed


if __name__ == '__main__':
    print(getopt())