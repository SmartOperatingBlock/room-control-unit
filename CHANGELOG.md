## [1.10.2](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.10.1...1.10.2) (2023-05-30)


### Bug Fixes

* typo in serializer ([673e1bc](https://github.com/SmartOperatingBlock/room-control-unit/commit/673e1bc9bb6156047de4880b43409f1f8535ad2c))

## [1.10.1](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.10.0...1.10.1) (2023-05-29)


### Bug Fixes

* add initialization time ([7342caa](https://github.com/SmartOperatingBlock/room-control-unit/commit/7342caa9fb14d38b92798d3cf00d68847e52f4a4))


### General maintenance

* change default id of rooms ([191cc8b](https://github.com/SmartOperatingBlock/room-control-unit/commit/191cc8b8f47edab6ad0dc62253eed308b6f63bb9))

## [1.10.0](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.9.2...1.10.0) (2023-05-28)


### Features

* add catheter as implantable medical device ([03674e9](https://github.com/SmartOperatingBlock/room-control-unit/commit/03674e90970fb3893e04ea26faa844ae78610f70))


### Build and continuous integration

* **deps:** update arduino/setup-arduino-cli action to v1.1.2 ([50b8fcf](https://github.com/SmartOperatingBlock/room-control-unit/commit/50b8fcfcadba425e96f974197be9b3c788abb657))


### Performance improvements

* use a number type for person role in cards to save memory ([cd9de63](https://github.com/SmartOperatingBlock/room-control-unit/commit/cd9de6374eefa7308aa245bc9d197371b4a5752a))

## [1.9.2](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.9.1...1.9.2) (2023-05-03)


### Bug Fixes

* handle luminosity intensity instead of luminosity percentage ([2824483](https://github.com/SmartOperatingBlock/room-control-unit/commit/2824483090766d5b3afed8ebd1dd66eed6630f29))
* hvac system must start in off state ([d0d2fe8](https://github.com/SmartOperatingBlock/room-control-unit/commit/d0d2fe84761896c617b6201786a4709573958349))
* use luminosity instead of percentage in lights command ([1297c3c](https://github.com/SmartOperatingBlock/room-control-unit/commit/1297c3cb4fab1ec06ad0e2b6e81f677949b91148))
* use luminosity instead of percentage in lights command deserialization ([1d737e8](https://github.com/SmartOperatingBlock/room-control-unit/commit/1d737e8edd2ed5791d596264c07757a8d689a86f))


### Dependency updates

* **deps:** update dependency semantic-release-preconfigured-conventional-commits to v1.1.17 ([fd90f35](https://github.com/SmartOperatingBlock/room-control-unit/commit/fd90f35e3f065f61074f2ac28548edb9ffdfe66c))
* **deps:** update dependency semantic-release-preconfigured-conventional-commits to v1.1.19 ([fc224f3](https://github.com/SmartOperatingBlock/room-control-unit/commit/fc224f37e71bb7e1c8c6a930df2c6e31e996e6ec))
* **deps:** update dependency semantic-release-preconfigured-conventional-commits to v1.1.20 ([85a2063](https://github.com/SmartOperatingBlock/room-control-unit/commit/85a2063a27f8ad66abb0e5865412c1a6ff386296))
* **deps:** update dependency semantic-release-preconfigured-conventional-commits to v1.1.21 ([4e6d17e](https://github.com/SmartOperatingBlock/room-control-unit/commit/4e6d17eea5366db6c06c913f1a82742e575bf4ae))
* **deps:** update dependency semantic-release-preconfigured-conventional-commits to v1.1.22 ([d45d409](https://github.com/SmartOperatingBlock/room-control-unit/commit/d45d4090863dcd2463ae223e8a4594f6f5707e7c))
* **deps:** update dependency semantic-release-preconfigured-conventional-commits to v1.1.23 ([d0a43a6](https://github.com/SmartOperatingBlock/room-control-unit/commit/d0a43a60c594a5bea710df032ba7cc1229e373b8))
* **deps:** update dependency semantic-release-preconfigured-conventional-commits to v1.1.24 ([d221587](https://github.com/SmartOperatingBlock/room-control-unit/commit/d221587902a29c43412e9f4ec62dec616b8fabb5))
* **deps:** update dependency semantic-release-preconfigured-conventional-commits to v1.1.25 ([44b7680](https://github.com/SmartOperatingBlock/room-control-unit/commit/44b7680700a9ddc103b285240a7f2af23c712753))
* **deps:** update dependency semantic-release-preconfigured-conventional-commits to v1.1.26 ([b4a20d2](https://github.com/SmartOperatingBlock/room-control-unit/commit/b4a20d292cc445294e2433db820e963a3550142c))
* **deps:** update node.js to 18.15 ([3bc1a72](https://github.com/SmartOperatingBlock/room-control-unit/commit/3bc1a7261266cfae6475e2a37ef37d05eb5b9727))
* **deps:** update node.js to 18.16 ([14963c1](https://github.com/SmartOperatingBlock/room-control-unit/commit/14963c11be402fef48891b3f3ade00fa5fbfb6c7))


### Refactoring

* add constructors and handle the intensity with long instead of percentage ([22e8b81](https://github.com/SmartOperatingBlock/room-control-unit/commit/22e8b81308abd5146492a2f08d9c45e9d040b8e9))
* reflect update in actuator state event and use long instead of percentage ([abe54d4](https://github.com/SmartOperatingBlock/room-control-unit/commit/abe54d49c6c986280da12402595b462ef8bd79a0))

## [1.9.1](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.9.0...1.9.1) (2023-02-07)


### Refactoring

* add const to safe the code where needed ([eeffc4e](https://github.com/SmartOperatingBlock/room-control-unit/commit/eeffc4e3c75ab3ab9b6136cb263267905f2446a8))
* use this pointer to safe code ([246fa45](https://github.com/SmartOperatingBlock/room-control-unit/commit/246fa4587ae85732164d41e542611aa264e9f083))


### Documentation

* add documentation to actuator type ([b7273bd](https://github.com/SmartOperatingBlock/room-control-unit/commit/b7273bdc406a5da8ac02c02b6f029edb39274bd5))
* correct typo ([eccce27](https://github.com/SmartOperatingBlock/room-control-unit/commit/eccce27271e0639e4541695a1e9577c30bf87726))
* correct typos ([e26cad7](https://github.com/SmartOperatingBlock/room-control-unit/commit/e26cad7d306d45bf144ad4e47d486b654b4ca467))
* document gcd internal function ([66c8f9a](https://github.com/SmartOperatingBlock/room-control-unit/commit/66c8f9a19f9c9cf59e75cf732cf3edd73d92e869))
* update constructor docs ([cecaaef](https://github.com/SmartOperatingBlock/room-control-unit/commit/cecaaefc435ec9acbac90ea59236a3615a7d7747))
* update serialization interfaces documentation ([659ff6d](https://github.com/SmartOperatingBlock/room-control-unit/commit/659ff6d81780326fea6f3de1c626397de753fd92))
* update task documentation ([b74b2e0](https://github.com/SmartOperatingBlock/room-control-unit/commit/b74b2e0d1cd095052c41de55061bd7831b681826))


### General maintenance

* change actuator type serialization strategy ([c82a4d4](https://github.com/SmartOperatingBlock/room-control-unit/commit/c82a4d4ba42f05c941e740ba6286ed20939f4c99))
* change visibility of abstract command constructor ([e0c4d26](https://github.com/SmartOperatingBlock/room-control-unit/commit/e0c4d26e6d2a6dfaefb3e87a6f1a791aa6c3ba02))
* change visibility of abstract event constructor ([99f72a3](https://github.com/SmartOperatingBlock/room-control-unit/commit/99f72a37ee47656324b9e6b6fa2dc22f3b5ccd0c))
* delete unused macro ([9944bca](https://github.com/SmartOperatingBlock/room-control-unit/commit/9944bca02b516b871b7a84154d10861a9c39c6ec))
* increase deserializer buffer base size ([d6e98d6](https://github.com/SmartOperatingBlock/room-control-unit/commit/d6e98d6e728c09dcc84230ff68ff110b58589ff6))
* make deconstructor virtual ([ed206c3](https://github.com/SmartOperatingBlock/room-control-unit/commit/ed206c3067ca58b8f4342531a7a28ad949ab27f4))
* update types ([edc4a4f](https://github.com/SmartOperatingBlock/room-control-unit/commit/edc4a4f14a0b90eb5e739eb32298d11f4d586f32))

## [1.9.0](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.8.0...1.9.0) (2023-02-05)


### Features

* implement discovery task ([8afa4ca](https://github.com/SmartOperatingBlock/room-control-unit/commit/8afa4ca9db7e89dc7f2a4cae6a2c3c56ffd0f48f))


### Bug Fixes

* avoid size computation due to possible errors when dealing with double pointers ([a71260d](https://github.com/SmartOperatingBlock/room-control-unit/commit/a71260d5ae758001704de64114df6bb3876754e6))
* solve ambiguity in inheritance ([175acd0](https://github.com/SmartOperatingBlock/room-control-unit/commit/175acd0f5712b92adcf8b2bde27c3b6b93ebf067))


### Refactoring

* add const to parameter ([f4afdcc](https://github.com/SmartOperatingBlock/room-control-unit/commit/f4afdcca7c829215acf89578810b709b78dcad37))
* refactor init code ([0de8d98](https://github.com/SmartOperatingBlock/room-control-unit/commit/0de8d98c759b6375f9e86f4d413d3cd63ecee0de))


### General maintenance

* adapt stream to new constructor ([e0dd942](https://github.com/SmartOperatingBlock/room-control-unit/commit/e0dd94239b9620af9fe1405ba9d241028940cf4f))
* add discovery task context ([149e8e7](https://github.com/SmartOperatingBlock/room-control-unit/commit/149e8e7f61fa6017d83f53389b896079d8a6a2fa))
* add discovery task to the system ([1b23fa6](https://github.com/SmartOperatingBlock/room-control-unit/commit/1b23fa644247fb32ede217bc9eafea8f68fd2125))
* add terminate method ([7aa83eb](https://github.com/SmartOperatingBlock/room-control-unit/commit/7aa83eb1de67c8ade0c50088254d9b7fa8d02577))
* add the possibility to delete a task ([6247309](https://github.com/SmartOperatingBlock/room-control-unit/commit/62473091ee891e3c58194630a544131f8548bbe0))
* allow to add on the front and on the tail ([2912a27](https://github.com/SmartOperatingBlock/room-control-unit/commit/2912a275cebdae2b867117a460eb8e2ee8ce55b7))

## [1.8.0](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.7.0...1.8.0) (2023-02-05)


### Features

* implement surgical light system task ([bfcb6bd](https://github.com/SmartOperatingBlock/room-control-unit/commit/bfcb6bddb882151d5a2cc5eb174f9f64825d3548))


### Bug Fixes

* correct type of surgical light command ([eba2b13](https://github.com/SmartOperatingBlock/room-control-unit/commit/eba2b13487e0c8ac56bdba13471999d2de464c2c))


### General maintenance

* add surgical light system context ([1df47f7](https://github.com/SmartOperatingBlock/room-control-unit/commit/1df47f7bb88e65c2844fee3f70e91c61ca0dcac7))
* add surgical light system to the system ([d44684f](https://github.com/SmartOperatingBlock/room-control-unit/commit/d44684fa3f9ba19925e50326364db220e338c0a1))
* invert type and person id in json result ([670b4ce](https://github.com/SmartOperatingBlock/room-control-unit/commit/670b4ce1a1a2a1abcee8fc01f24e15e7f90221d4))

## [1.7.0](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.6.0...1.7.0) (2023-02-04)


### Features

* implement ambient light system task ([e42d465](https://github.com/SmartOperatingBlock/room-control-unit/commit/e42d4650feb2118113affd0fd6defc1544a2407e))


### Bug Fixes

* correct light interface visibility ([353dc7b](https://github.com/SmartOperatingBlock/room-control-unit/commit/353dc7bca42e7ab155cedc361ed42d6a2773d7d3))


### Refactoring

* separate room events ([558a7c7](https://github.com/SmartOperatingBlock/room-control-unit/commit/558a7c7225357858de2f70c15e93c96dac4c33d0))


### General maintenance

* add ambient light system context ([8510650](https://github.com/SmartOperatingBlock/room-control-unit/commit/8510650fcbfa15cb25749d4b7c0ca86e18a43800))
* add ambient light system to the system ([449af66](https://github.com/SmartOperatingBlock/room-control-unit/commit/449af663f30f9928c19207df4eb3c6f4c1ea46b1))
* add anymatch ([0d3e51e](https://github.com/SmartOperatingBlock/room-control-unit/commit/0d3e51e0de546561905aef24445086a6413a6fad))
* add equal operator ([207f587](https://github.com/SmartOperatingBlock/room-control-unit/commit/207f587161fff5a034c78a031206ceed0b562279))
* implement getters ([39a7186](https://github.com/SmartOperatingBlock/room-control-unit/commit/39a718670e09339ee4a4f99100b17ca6ab80fcb7))
* increase number of tasks that the scheduler can handle ([ca1c018](https://github.com/SmartOperatingBlock/room-control-unit/commit/ca1c018bbe2a30729da61a045057056b86ee5151))
* rename pins ([dded643](https://github.com/SmartOperatingBlock/room-control-unit/commit/dded643fe76d3156cc8b18b32a60f134e8bccf6b))

## [1.6.0](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.5.0...1.6.0) (2023-02-04)


### Features

* implement hvac system task ([ead6111](https://github.com/SmartOperatingBlock/room-control-unit/commit/ead6111308fb1e54d0f3adc3f92820542cfede4e))


### Bug Fixes

* correct command passing strategy ([cd78627](https://github.com/SmartOperatingBlock/room-control-unit/commit/cd78627a40ca829c2042fc2aeffcc018b898976b))
* correct status deserialization ([63bf978](https://github.com/SmartOperatingBlock/room-control-unit/commit/63bf978afc6c35ee325c9fe26f69422e49120961))


### General maintenance

* add actuator id list ([a500cc6](https://github.com/SmartOperatingBlock/room-control-unit/commit/a500cc6f32e7ac25bd41831a06a1dedd5fa30faf))
* add hvac system context ([9fef994](https://github.com/SmartOperatingBlock/room-control-unit/commit/9fef99474bbe57bb665f099da4f111c16c260b39))
* add hvac system to the system ([de435ed](https://github.com/SmartOperatingBlock/room-control-unit/commit/de435ede71dcdbb5f7f43ee682de251fe71c5f04))
* implement getter and setter for speed and status ([05a6a21](https://github.com/SmartOperatingBlock/room-control-unit/commit/05a6a219e2ea72a7c39bfc7d56d0f97d4b0e290f))
* implement getters ([4bebc1d](https://github.com/SmartOperatingBlock/room-control-unit/commit/4bebc1df24177c65635584760db703059c1581eb))
* rename pins ([6265110](https://github.com/SmartOperatingBlock/room-control-unit/commit/6265110e6a910c46fa3615c1cf09989dbd4531a6))

## [1.5.0](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.4.0...1.5.0) (2023-02-04)


### Features

* implement command listener task ([98a77b7](https://github.com/SmartOperatingBlock/room-control-unit/commit/98a77b7ec3fb3a09d0a9094dd3d21423545ee5fb))


### General maintenance

* add command listener context ([668a98b](https://github.com/SmartOperatingBlock/room-control-unit/commit/668a98bd7a463e1ed9f670d9697b057884bba2e6))
* add command listener to the system ([0c03c16](https://github.com/SmartOperatingBlock/room-control-unit/commit/0c03c164c5882268cde4849f2a6ee1df61be3ab5))
* change protocol ([5f0a73a](https://github.com/SmartOperatingBlock/room-control-unit/commit/5f0a73a11a374479c08c4b8e9d06d0685cba8c2a))
* change surgical light pin name ([8215580](https://github.com/SmartOperatingBlock/room-control-unit/commit/8215580c2ac18c493a406ee768db6683f61ff55f))

## [1.4.0](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.3.0...1.4.0) (2023-02-04)


### Features

* implement operating room advanced monitoring task ([adf3e05](https://github.com/SmartOperatingBlock/room-control-unit/commit/adf3e0581f5f35db970a1eb62355425c06ad2fee))


### Bug Fixes

* correct memory issues ([c4cbf5c](https://github.com/SmartOperatingBlock/room-control-unit/commit/c4cbf5cc7118051c89305ddcf8e8860d2528dfca))


### General maintenance

* add operating room advanced monitoring context ([1f86895](https://github.com/SmartOperatingBlock/room-control-unit/commit/1f8689533fb8bd997d0c2ec4816d5bf3962c074c))
* add operating room advanced monitoring task to the system ([f7d0313](https://github.com/SmartOperatingBlock/room-control-unit/commit/f7d0313a719fde6aa72d6647fc2a87870c41a785))
* change patient on operating block event to take room ([3e8eefd](https://github.com/SmartOperatingBlock/room-control-unit/commit/3e8eefd424e3e151f73ff10562c74ec300188dcf))

## [1.3.0](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.2.0...1.3.0) (2023-02-04)


### Features

* implement people tracking task ([1cf0c2c](https://github.com/SmartOperatingBlock/room-control-unit/commit/1cf0c2cb1e3a0c3bec85895ec8d9131bef90c9aa))


### Dependency updates

* **deps:** update node.js to 18.14 ([90c726c](https://github.com/SmartOperatingBlock/room-control-unit/commit/90c726c3be070b192985c4e2061ca154b076469d))


### General maintenance

* add delete functionality ([fdc23c3](https://github.com/SmartOperatingBlock/room-control-unit/commit/fdc23c3c7f61d3ce12c83bb0c1e88e0fb8bdbd27))
* add pair concept ([dec02fc](https://github.com/SmartOperatingBlock/room-control-unit/commit/dec02fc5388e08625cecd8f63681dc43293749d8))
* add people tracking context ([77a7bbc](https://github.com/SmartOperatingBlock/room-control-unit/commit/77a7bbc0616672d3b8e8762be3f07e24342c5e8e))
* add people tracking task to the system ([adc1320](https://github.com/SmartOperatingBlock/room-control-unit/commit/adc132062f8896ea1a8a033cb0e1c081dd8e4af5))
* change exist strategy to take the element to check ([4f778ce](https://github.com/SmartOperatingBlock/room-control-unit/commit/4f778ce4d191d176da73c8a87f343feb397abb47))
* change serialization of person track exit event ([e3d58f2](https://github.com/SmartOperatingBlock/room-control-unit/commit/e3d58f21c10d8c33d7e0246ffd7537678fcfd791))
* change storing strategy ([deaa7bf](https://github.com/SmartOperatingBlock/room-control-unit/commit/deaa7bf4433100a3229481de6d12d44e78a13c85))
* make tracker aware of previous and next room connected to it ([1d711c8](https://github.com/SmartOperatingBlock/room-control-unit/commit/1d711c845eb6c210a92135af9c80f6c7869173bf))
* update pin list ([52ffb25](https://github.com/SmartOperatingBlock/room-control-unit/commit/52ffb256871672552f8f1db31f57ff37c3d1c9b1))
* update README workflow badge ([08218b3](https://github.com/SmartOperatingBlock/room-control-unit/commit/08218b388a3b6524fc5033c99369e8f529e40b81))

## [1.2.0](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.1.0...1.2.0) (2023-02-03)


### Features

* implement presence monitoring task ([b6bd985](https://github.com/SmartOperatingBlock/room-control-unit/commit/b6bd985c99235d8278170934f5e5eaeecc94dd57))


### General maintenance

* add presence monitoring context ([a6e0508](https://github.com/SmartOperatingBlock/room-control-unit/commit/a6e0508034785935ffa90c54fc005b0535977841))
* add presence monitoring task to the system ([ccc4388](https://github.com/SmartOperatingBlock/room-control-unit/commit/ccc438858d81c06f893e1a64b54f9dbc2a099109))

## [1.1.0](https://github.com/SmartOperatingBlock/room-control-unit/compare/1.0.0...1.1.0) (2023-02-03)


### Features

* implement luminosity monitoring task ([0e579f0](https://github.com/SmartOperatingBlock/room-control-unit/commit/0e579f0b8de752edee1333374dab0f4779d19229))


### General maintenance

* add luminosity monitoring context ([82f8cac](https://github.com/SmartOperatingBlock/room-control-unit/commit/82f8cac49acccf66f802079089f0fed43a3be7bc))
* add luminosity monitoring task to the system ([10bc1eb](https://github.com/SmartOperatingBlock/room-control-unit/commit/10bc1eb258f27ef195b65de993cf92732f4a3834))
* set lux as luminosity unit ([0f33841](https://github.com/SmartOperatingBlock/room-control-unit/commit/0f33841f975fd928014ce2e88b4a1787bce347f8))

## 1.0.0 (2023-02-03)


### Features

* add temperature and humidity monitoring task ([9801004](https://github.com/SmartOperatingBlock/room-control-unit/commit/9801004eec39bae7d6462b6709e693f9eebcc83b))
* implement gateway exporter task ([2ce11c5](https://github.com/SmartOperatingBlock/room-control-unit/commit/2ce11c58c357f7f42b12e5d7adc2a3fc7378f6b7))


### Bug Fixes

* add String dependency ([8ac6fc5](https://github.com/SmartOperatingBlock/room-control-unit/commit/8ac6fc5bd32d2f294f16f0e5c6329d1d52aaa8dd))
* add virtual to task inheritance to avoid ambiguity ([888fecd](https://github.com/SmartOperatingBlock/room-control-unit/commit/888fecd3eca64dd066181d73377c7b8de7057446))
* correct miss pointer ([5c8eee0](https://github.com/SmartOperatingBlock/room-control-unit/commit/5c8eee038a2dd4d616dc13fce9753b5e2f2ae81e))
* pass function to foreach with template ([bb23f52](https://github.com/SmartOperatingBlock/room-control-unit/commit/bb23f524ba533b18e5a3f6a6c0f4fb5d12390a9b))


### Style improvements

* format code ([ae466fd](https://github.com/SmartOperatingBlock/room-control-unit/commit/ae466fda8fb50b72d3ea1a50b465cc6e46c801c3))
* **room-cu-scheme:** refactor rfid readers wiring ([2d07616](https://github.com/SmartOperatingBlock/room-control-unit/commit/2d07616d3e5abc5e1ae1dac8a91c2472a58e0695))
* space between methods ([57bde2d](https://github.com/SmartOperatingBlock/room-control-unit/commit/57bde2da840f94587b0e16244deb4ee8cfb9210d))


### Documentation

* **room-cu-scheme:** add heating and cooling wires and notes ([c93492f](https://github.com/SmartOperatingBlock/room-control-unit/commit/c93492f0a7df4ceaf3a4eb63ab70343f0dd15da9))
* **room-cu-scheme:** add motor driver to control fan ([07c1553](https://github.com/SmartOperatingBlock/room-control-unit/commit/07c15530cb35cb03301ae7e17c7e35846f613611))
* **room-cu-scheme:** add rfid readers to the scheme ([c9f8355](https://github.com/SmartOperatingBlock/room-control-unit/commit/c9f83556d3519d46b1398afb5e7bf89a151f7945))
* **room-cu-scheme:** change heating cooling leds pin ([fecca4a](https://github.com/SmartOperatingBlock/room-control-unit/commit/fecca4a8c293cc9c2c7660a3fc086752344fe360))
* **room-cu-scheme:** room control unit diagram scheme ([a0a6f70](https://github.com/SmartOperatingBlock/room-control-unit/commit/a0a6f7039d0507ace3e6a9ab28529c7fba55b09f))
* update implantable device tracker concept documentation ([81a8344](https://github.com/SmartOperatingBlock/room-control-unit/commit/81a83441ce76e73c3db58e088582e65742828762))
* update person tracker documentation ([01ea611](https://github.com/SmartOperatingBlock/room-control-unit/commit/01ea6119ed24e921c2ece8cf763d1310bdf4a878))


### Refactoring

* change path and enum serialization technique ([bd2dbf9](https://github.com/SmartOperatingBlock/room-control-unit/commit/bd2dbf95abc46d9a89db26fa0e9f07d01624cdb1))
* clean the architecture ([f6fa2eb](https://github.com/SmartOperatingBlock/room-control-unit/commit/f6fa2eb5411befc0ed6cfd821a22c30fe9d6435e))
* compute size automatically ([cbfd00a](https://github.com/SmartOperatingBlock/room-control-unit/commit/cbfd00a778a65ac4292799218c013cd0f322cc1f))
* convert null to c++ nullptr ([1f69aec](https://github.com/SmartOperatingBlock/room-control-unit/commit/1f69aecf1741ce02ff45485c2b8886b97df63697))
* delete auxiliary data in setPeriod ([b0cf3d7](https://github.com/SmartOperatingBlock/room-control-unit/commit/b0cf3d77ab745d9162d9ee01eff9de1e486b6b4a))
* protect sensor count ([d8edc37](https://github.com/SmartOperatingBlock/room-control-unit/commit/d8edc3728a1228bd9eb50171ce3697b6ddf28395))
* set period as constant because for now it can't change ([c35e506](https://github.com/SmartOperatingBlock/room-control-unit/commit/c35e506fe0709a2c008fda637fc7de448f9f41b7))
* split hvac system in different actuators to be better managed ([ecd7f05](https://github.com/SmartOperatingBlock/room-control-unit/commit/ecd7f0538590cca71ea82f5b24e2a55082c80d36))


### General maintenance

* adapt to new ArrayStream constructor ([900b4e6](https://github.com/SmartOperatingBlock/room-control-unit/commit/900b4e645df6e5544a85b6ad4461201adf2af1dc))
* add Actuator concept and so set actuator id to actuators ([bca14e0](https://github.com/SmartOperatingBlock/room-control-unit/commit/bca14e078d291a25e79981679007ed0777239178))
* add actuator type ([bd07efc](https://github.com/SmartOperatingBlock/room-control-unit/commit/bd07efceabd8f47bee10c76afc02f4342e001058))
* add array stream util ([0b90bd4](https://github.com/SmartOperatingBlock/room-control-unit/commit/0b90bd42adbd1dd894bd617cf0258c14de9d8dd3))
* add command deserializer interface ([6821b21](https://github.com/SmartOperatingBlock/room-control-unit/commit/6821b2150d62d9661cf92af05590c4dd0a9efad2))
* add commands ([786e787](https://github.com/SmartOperatingBlock/room-control-unit/commit/786e787df0c75e9b857148b9a69c850775211760))
* add comment on power save ([e9be0b3](https://github.com/SmartOperatingBlock/room-control-unit/commit/e9be0b3a9c8fef2b41d0d21465ce1dc1d33bcd86))
* add communication io concepts ([91dd177](https://github.com/SmartOperatingBlock/room-control-unit/commit/91dd1773e29bc71b4830445577cdb05f5b32a572))
* add concepts about luminosity temperature and humidity ([4722096](https://github.com/SmartOperatingBlock/room-control-unit/commit/4722096787e343bf4dde63ca397c2c8c8a0e1f17))
* add context provider to simplify code in the main script ([6e6afe5](https://github.com/SmartOperatingBlock/room-control-unit/commit/6e6afe5765da7a4c591423338e90a2dd2a51fbdf))
* add copyright header to main file ([ae6c19a](https://github.com/SmartOperatingBlock/room-control-unit/commit/ae6c19a3e704842001065ac87edfb43f6724394e))
* add deconstructor to abstract fsm ([3eec005](https://github.com/SmartOperatingBlock/room-control-unit/commit/3eec0054a8758a07c536b218ab5575c05854dbe5))
* add default constructor ([362acf4](https://github.com/SmartOperatingBlock/room-control-unit/commit/362acf4d957007b21288e2c7ba4aae746ca9efcf))
* add digital pin utils ([d08c510](https://github.com/SmartOperatingBlock/room-control-unit/commit/d08c510cd09b45c79498bbf7ea0c3f23411cc3a2))
* add empty ino file ([a3db53d](https://github.com/SmartOperatingBlock/room-control-unit/commit/a3db53d5eb896c982e2cdd94ac2f83178ce27ab4))
* add environment luminosity sensor ([f07d49a](https://github.com/SmartOperatingBlock/room-control-unit/commit/f07d49a9691bae7dcf27b58233b3dfbf2ef87c41))
* add foreach ([ea8bfac](https://github.com/SmartOperatingBlock/room-control-unit/commit/ea8bface58a03bf9c98f9c3cb232bdd09e4cec90))
* add fsm periods ([e00dd9d](https://github.com/SmartOperatingBlock/room-control-unit/commit/e00dd9d255ac1acbeec07897a51f68367e527cce))
* add gateway exporter task to the system ([3fb157d](https://github.com/SmartOperatingBlock/room-control-unit/commit/3fb157dfa509c95f1eeedf95a56c246306c78626))
* add hvac base concept ([f3b0429](https://github.com/SmartOperatingBlock/room-control-unit/commit/f3b04290cd2700d46bd9c1b40e8ad82b77d93225))
* add implantable medical device tracker implementation ([890b52b](https://github.com/SmartOperatingBlock/room-control-unit/commit/890b52bc39408273dbba720de9a49b2d19bf58e6))
* add init of the system ([21d9bc3](https://github.com/SmartOperatingBlock/room-control-unit/commit/21d9bc3f86aba59b9f92989b663b09b9c013b438))
* add issue templates ([1b4b4b1](https://github.com/SmartOperatingBlock/room-control-unit/commit/1b4b4b1418036581210a6cd0541ea7ac6fba39b5))
* add json command serializer ([731ed79](https://github.com/SmartOperatingBlock/room-control-unit/commit/731ed790eb1e606031a1762be352ba8a82b30347))
* add light and surgical light concepts ([2ff75bf](https://github.com/SmartOperatingBlock/room-control-unit/commit/2ff75bfab44cfbb93efbbc1a073eecd64b79b190))
* add light and surgical light implementation ([ec7525e](https://github.com/SmartOperatingBlock/room-control-unit/commit/ec7525e44aded7e42b7924b2cb19e5e7c070c59e))
* add math helper to compute the gcd ([af1795c](https://github.com/SmartOperatingBlock/room-control-unit/commit/af1795c640763afba7bf754feb50e48cacd4fa5e))
* add mergify config ([6a271ab](https://github.com/SmartOperatingBlock/room-control-unit/commit/6a271ab64e77f801591305a096c4bcef96ba3cc1))
* add new constructor to RoomEvent in order to set also a custom event type ([a0e20d8](https://github.com/SmartOperatingBlock/room-control-unit/commit/a0e20d82b4bd798464adab90b90ad7d115c16f48))
* add patient and implantable medical device model ([c960bda](https://github.com/SmartOperatingBlock/room-control-unit/commit/c960bda723e019029e71e67299c8f99a6d363b72))
* add percentage concept ([03b8850](https://github.com/SmartOperatingBlock/room-control-unit/commit/03b8850deac0b4281a751515883160d917427327))
* add person tracker implementation ([a62f701](https://github.com/SmartOperatingBlock/room-control-unit/commit/a62f7019bb396ef24c5522aca1436145a2d73a89))
* add pin list ([eb13738](https://github.com/SmartOperatingBlock/room-control-unit/commit/eb1373857443c68bf70a93ec3a5894ade415445c))
* add power status concept ([c9a83b0](https://github.com/SmartOperatingBlock/room-control-unit/commit/c9a83b08dc24fbabed1870b76481ba98df5ed575))
* add presence sensor ([3c54c89](https://github.com/SmartOperatingBlock/room-control-unit/commit/3c54c8970f2dd24c2dd58fac70f4613a654f4914))
* add presence status to presence event ([68f6aec](https://github.com/SmartOperatingBlock/room-control-unit/commit/68f6aec62b3946a6d578bdf2e9851abefd577cf6))
* add public keyboard ([833f310](https://github.com/SmartOperatingBlock/room-control-unit/commit/833f31099a6337c75a5a54ebc902cc01115cf623))
* add renovate config ([2d63960](https://github.com/SmartOperatingBlock/room-control-unit/commit/2d63960b3834f61b270f497ebcfcc9e904faa708))
* add rfid reader ([f6c35a2](https://github.com/SmartOperatingBlock/room-control-unit/commit/f6c35a2867dc85cc823d3e67eb3c2134543a045c))
* add room concept ([813e5de](https://github.com/SmartOperatingBlock/room-control-unit/commit/813e5dedf937fac99aee2f7a480ec38e43f9e798))
* add room equipment ([fec49ce](https://github.com/SmartOperatingBlock/room-control-unit/commit/fec49cec0937d6959a3eb5ad93788ec94c763c1a))
* add room id configuration ([b60699e](https://github.com/SmartOperatingBlock/room-control-unit/commit/b60699ed9381946dca0021d54beb498eae807e25))
* add scheduler ([9e514fc](https://github.com/SmartOperatingBlock/room-control-unit/commit/9e514fcf74df8e1c94a725e516a036dd5e7524db))
* add serial interface ([3d7cb6e](https://github.com/SmartOperatingBlock/room-control-unit/commit/3d7cb6ec649071a2eb276bbb8e5311e6ad6c7097))
* add simple list ([851ed3f](https://github.com/SmartOperatingBlock/room-control-unit/commit/851ed3fbb1efaeb9aaf27baa993ef8599141a58e))
* add some events ([acdd9a4](https://github.com/SmartOperatingBlock/room-control-unit/commit/acdd9a4738d413146184588832bc0f0b24097ee8))
* add stretcher pressure sensor ([ec264ce](https://github.com/SmartOperatingBlock/room-control-unit/commit/ec264ce7a197f339e4fe11a3f4c83dd5886bb65a))
* add system ([0661597](https://github.com/SmartOperatingBlock/room-control-unit/commit/06615970e20b0d66f93760289fca7ff57dbf8794))
* add task definition and abstract implementation ([6cffde6](https://github.com/SmartOperatingBlock/room-control-unit/commit/6cffde6d17ca2c26fbe9012c0ebde58a503a6da0))
* add task modeled as fsm ([92696a3](https://github.com/SmartOperatingBlock/room-control-unit/commit/92696a3ccdf857b0b473153d5a5021b3ed81a0fd))
* add temperature and humidity sensor ([fd5b35e](https://github.com/SmartOperatingBlock/room-control-unit/commit/fd5b35e77a0d7e0d0a38e1ea4a51e77874791c66))
* add temperature and monitoring task to the system ([1430f2e](https://github.com/SmartOperatingBlock/room-control-unit/commit/1430f2e283106ec226fb281d648db03083826b00))
* add tracking concepts ([1d5deb2](https://github.com/SmartOperatingBlock/room-control-unit/commit/1d5deb2ed9cba5c1176761a7ae3c3a54dba43e90))
* add virtual deconstructor to allow inheritance safely ([7d7876c](https://github.com/SmartOperatingBlock/room-control-unit/commit/7d7876cc534a362e34703ff5373fbc3663289c34))
* adopt percentage concept instead of primitive ([595b75e](https://github.com/SmartOperatingBlock/room-control-unit/commit/595b75edaa9e3847652a95dbcce77bf2ef512efa))
* change clean strategy considering deep-cleaning ([b8b3260](https://github.com/SmartOperatingBlock/room-control-unit/commit/b8b3260fa71491d25480733db8c70992acfdd7a7))
* change humidity type to percentage ([c759fc1](https://github.com/SmartOperatingBlock/room-control-unit/commit/c759fc15dc5c6f1114354964cae9f6ba8858c8a1))
* change way to handle memory cleaning ([117d491](https://github.com/SmartOperatingBlock/room-control-unit/commit/117d4911aeab5f2e47faaeb284a5a10afc2ca729))
* correct names ([24cd6c1](https://github.com/SmartOperatingBlock/room-control-unit/commit/24cd6c1eb09577535ca8eca112c80e92b4c64225))
* create context for gateway exporter ([6f97f21](https://github.com/SmartOperatingBlock/room-control-unit/commit/6f97f2149f00403dc3e91f1b1fe1d47199bc62ae))
* create new stack array in map method ([b4fa318](https://github.com/SmartOperatingBlock/room-control-unit/commit/b4fa318e3c64c2c10bf6fdf0f5b815d64ab36fa8))
* create serializable interface ([bded619](https://github.com/SmartOperatingBlock/room-control-unit/commit/bded6199fffcd29c4c3bc177d99364dae5148e58))
* create serializer interface ([c6f4818](https://github.com/SmartOperatingBlock/room-control-unit/commit/c6f4818b4dca78e4f1eafd875d42f1ba1cf89023))
* define events ([1ca6db4](https://github.com/SmartOperatingBlock/room-control-unit/commit/1ca6db4231f6339bee80881723af9cfc1f830905))
* implement accept function in serializable events ([f1abb56](https://github.com/SmartOperatingBlock/room-control-unit/commit/f1abb5689d4c4fb115e9f9be96cee20d59dabe4e))
* implement getters ([848a276](https://github.com/SmartOperatingBlock/room-control-unit/commit/848a276ca7cdc1b985345d88eeac08d8a350ca97))
* implement hvac system ([28b527f](https://github.com/SmartOperatingBlock/room-control-unit/commit/28b527fac3856fec8679359bdb61ae09a39858d2))
* implement json serializer for events serialization ([13ab38d](https://github.com/SmartOperatingBlock/room-control-unit/commit/13ab38d0b7ca38772a615ed1a8b70774f12436bd))
* import string in models ([c8b6516](https://github.com/SmartOperatingBlock/room-control-unit/commit/c8b6516f52867e5f36933b18af722354af274197))
* make hvac concept an interface ([ce7babe](https://github.com/SmartOperatingBlock/room-control-unit/commit/ce7babe3dc42050978e0bf81a372dfb6758b62b0))
* move logic to app package ([ea55acb](https://github.com/SmartOperatingBlock/room-control-unit/commit/ea55acbeda681f2d78168e06a64f910ef6fdcf10))
* move PowerStatus concept to domain ([0c8f353](https://github.com/SmartOperatingBlock/room-control-unit/commit/0c8f353d71c8e726bdd6dc6d8cf8987160230668))
* move real io to subdirectory ([7cd9925](https://github.com/SmartOperatingBlock/room-control-unit/commit/7cd99255e834ae1c0bd50a9d00c26cf4e407d33d))
* move scheduler and task under system package ([eac85b3](https://github.com/SmartOperatingBlock/room-control-unit/commit/eac85b31c7ad9a1658b38d94502afb103700ad4b))
* override task methods ([e4eea38](https://github.com/SmartOperatingBlock/room-control-unit/commit/e4eea38108791c868b3d0394771d722721e5823f))
* put semicolon ([f246205](https://github.com/SmartOperatingBlock/room-control-unit/commit/f246205ace4b1b6630c702f8e75d753a8d74a0c0))
* rename Button in PressureSensor to be more related to domain ([6126074](https://github.com/SmartOperatingBlock/room-control-unit/commit/6126074a338719559371957bfd1cd2e56b4fbf40))
* rename mergify config file ([af4d842](https://github.com/SmartOperatingBlock/room-control-unit/commit/af4d84283cfc6c93b27be994e315e73ae49ec240))
* set the json size ([732ff9a](https://github.com/SmartOperatingBlock/room-control-unit/commit/732ff9a50a21a99107c2c2659eebe88681379e27))
* simple example of functioning ([15748f4](https://github.com/SmartOperatingBlock/room-control-unit/commit/15748f4ddf5d219310090a87b6b5107b595addfd))
* solve cycling include ([94622ab](https://github.com/SmartOperatingBlock/room-control-unit/commit/94622ab477f2065494106da0b0d73160ef10e579))
* specify type in map stream creation ([cf72309](https://github.com/SmartOperatingBlock/room-control-unit/commit/cf72309fa2195153764dfb667618a13876f26516))
* update gitignore ([9a45ee7](https://github.com/SmartOperatingBlock/room-control-unit/commit/9a45ee7e217feb655a060bdcd041206f53f89162))
* update gitignore for arduino project ([40ea447](https://github.com/SmartOperatingBlock/room-control-unit/commit/40ea4475c06c5c97c26afff0f4e609fce19cd49d))
* update hvac concept ([5faebbf](https://github.com/SmartOperatingBlock/room-control-unit/commit/5faebbf34de4e856a6e446588d7ed45192ea1b54))
* update name of implantable medical device type ([71da768](https://github.com/SmartOperatingBlock/room-control-unit/commit/71da768a47ef34a0231c778376a8fff64f3b927d))
* update README ([76f002b](https://github.com/SmartOperatingBlock/room-control-unit/commit/76f002bb951858acebc32b9419ece3761950e461))
* update README with wofkflow status badge ([ec72976](https://github.com/SmartOperatingBlock/room-control-unit/commit/ec729761757447639bde5bca34289003e7ffbef5))
* use intensity percentage in actuator event ([9110282](https://github.com/SmartOperatingBlock/room-control-unit/commit/91102827c727098eeb7e0c2b27a2c78f10cd30c4))


### Build and continuous integration

* add arduino json library to build ([36d049d](https://github.com/SmartOperatingBlock/room-control-unit/commit/36d049d16d97319e953e82b3cb71f422b4a2122d))
* add build workflow for arduino code ([afdc931](https://github.com/SmartOperatingBlock/room-control-unit/commit/afdc9316d7955a8ae7ab46deca598bd4645354ca))
* add libraries to arduino compilation ([5aeb700](https://github.com/SmartOperatingBlock/room-control-unit/commit/5aeb7000572edc3baca7bbffcdd3ee4ea52f46f9))
* add semantic release ([028e0a8](https://github.com/SmartOperatingBlock/room-control-unit/commit/028e0a83bb5ca8d228b36df33935edac847fdecd))
* change secret for semantic release ([cddc42c](https://github.com/SmartOperatingBlock/room-control-unit/commit/cddc42cfed6cfa220145d0fb9f2fcab2db9970ad))
* change workflow name ([41afe1b](https://github.com/SmartOperatingBlock/room-control-unit/commit/41afe1bd7d35ae6a5422287cd4aeece1f42ec12b))
* set deployment token ([5532c81](https://github.com/SmartOperatingBlock/room-control-unit/commit/5532c812e0faf3841dd97e6d0a0d58f5fda59a28))
* update build matrix ([c1021cc](https://github.com/SmartOperatingBlock/room-control-unit/commit/c1021ccf83f24517d7df4cf1b0f5a70bc6673fd1))
* update build workflow ([d6fa39b](https://github.com/SmartOperatingBlock/room-control-unit/commit/d6fa39b3d0687c997e2bccbb51569080ec14c0ed))
* update build workflow ([b2e43b1](https://github.com/SmartOperatingBlock/room-control-unit/commit/b2e43b1ab11ed0653d6b94cb5f8e0bb773a794a5))
