import argparse

from loguru import logger
from exampleGenerators.problem1008 import generate1008


def main():
    generator = {
        1008: generate1008,
    }
    opts = readOpts()

    if not generator.get(opts.code, False):
        logger.error(f"generator for code {opts.code} does not exist")
        return

    generator[opts.code](opts.num)
    logger.info(f"successfully generated test examples for problem with code {opts.code}")

def readOpts() -> argparse.Namespace:
    """read arguments (options) from stdin

    Returns:
        argparse.Namespace: arguments from stdin
    """
    parser = argparse.ArgumentParser()
    parser.add_argument('-c', '--code', type=int, required=True, help='Problem code')
    parser.add_argument('-n', '--num', type=int, default=100, help='Number of test examples')

    return parser.parse_args()

if __name__ == '__main__':
    main()
