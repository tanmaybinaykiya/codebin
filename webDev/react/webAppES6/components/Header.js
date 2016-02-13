class Header extends React.Component {
	constructor(props) {
        super(props);
    }

	render(){
		return (
			<div className="header">
				<div className="justForCentering">
					<div className="headerText">
						<span><a id="homeLink" href="index.html">Vacation</a></span>
						<span>Easiest way to shop for travel </span>
					</div>
					<div id="logo"></div>
				</div>
			</div>
		);
	}

}