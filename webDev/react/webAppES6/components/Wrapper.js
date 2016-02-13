class Wrapper extends React.Component{
	constructor(props) {
        super(props);
        this.state  = {page: props.page};
    }

    render() {
		switch(this.state.page) {
		case 'lala':
			return (
				<div id='wrapper'>
					<Header />
					<HomePage />
					<Footer />
				</div>
			);
			break;
		case 'nana':
			return (
				<div id='wrapper'>
					<Header />
					<NanaPage />
					<Footer />
				</div>
			);
			break;
		default:
			return (
				<div id='wrapper'>
					<Header />
					<HomePage />
					<Footer />
				</div>
			);
		}
	}
}

Wrapper.defaultProps = { page: 'lala'};