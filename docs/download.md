# Download

## Manual Download

DDX can be downloaded as a [PROS](https://pros.cs.purdue.edu/) template from the releases tab in the DDX GitHub repository.

## Depot Download

If you don't want to re-download DDX every time a new release comes out, we've set up a depot to make the updating process easier.

You can use the following commands to add the depot to your `pros-cli` installation.

```bash
pros c add-depot DDX https://raw.githubusercontent.com/Doral-Dynamics/DDX/depot/stable.json # adds DDX stable depot
pros c apply DDX # applies latest stable version of DDX
```

To update DDX, all you have to do is run the following command:

```bash
pros c upgrade
```

### Beta Depot

```{warning}
Beta versions of DDX may not be fully tested or documented. Use at your own risk.
```

If you'd like to use a beta version of DDX you can add our beta depot like so:

```bash
pros c add-depot DDX https://raw.githubusercontent.com/Doral-Dynamics/DDX/depot/beta.json # adds DDX beta depot
```

## Further steps

Once you've downloaded DDX we recommend you take a look at our [tutorials](./tutorials/1_getting_started.md).
